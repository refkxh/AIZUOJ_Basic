#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
bool vis[107];
int G[107][107], dist[107];
queue<int> q;
int main() {
    int n;
    scanf("%d", &n);
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
    	int u, k;
    	scanf("%d%d", &u, &k);
    	for (int j = 0; j < k; j++) {
    		scanf("%d", &G[u][j]);
		}
	}
	dist[1] = 0;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; G[cur][i]; i++) {
			if (dist[G[cur][i]] == -1) dist[G[cur][i]] = dist[cur] + 1;
			else dist[G[cur][i]] = min(dist[G[cur][i]], dist[cur] + 1);
			if (!vis[G[cur][i]]) {
				q.push(G[cur][i]);
				vis[G[cur][i]] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", i, dist[i]);
	}
    return 0;
}
