#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 7;
bool vis[MAXN];
int dist[MAXN];
vector<pair<int, int> > G[MAXN];
queue<int> q;
int bfs(int st) {
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	q.push(st);
	vis[st] = true;
	int ret = st, maxd = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			if (!vis[G[cur][i].first]) {
				vis[G[cur][i].first] = true;
				q.push(G[cur][i].first);
				dist[G[cur][i].first] = dist[cur] + G[cur][i].second;
				if (dist[G[cur][i].first] > maxd) {
					maxd = dist[G[cur][i].first];
					ret = G[cur][i].first;
				}
			}
		}
	}
	return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
    	int s, t, w;
    	scanf("%d%d%d", &s, &t, &w);
    	G[s].push_back(make_pair(t, w));
    	G[t].push_back(make_pair(s, w));
	}
	printf("%d\n", dist[bfs(bfs(0))]);
	return 0;
}
