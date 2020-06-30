#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 7, INF = 5e5 + 7;
int d[MAXN];
struct node {
	int id, dist;
	node(int id, int dist) :id(id), dist(dist) {}
	bool operator < (const node &rhs) const {
		return dist > rhs.dist;
	}
};
vector<pair<int, int> > G[MAXN];
priority_queue<node> nodes;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
    	d[i] = INF;
	}
    for (int i = 0; i < n; i++) {
    	int u, k;
    	scanf("%d%d", &u, &k);
    	for (int j = 0; j < k; j++) {
    		int v, c;
    		scanf("%d%d", &v, &c);
    		G[u].push_back(make_pair(v, c));
		}
	}
	nodes.push(node(0, 0));
	while (!nodes.empty()) {
		node tmp = nodes.top();
		nodes.pop();
		if (tmp.dist > d[tmp.id]) continue;
		int cnt = G[tmp.id].size();
		for (int i = 0; i < cnt; i++) {
			if (d[G[tmp.id][i].first] > d[tmp.id] + G[tmp.id][i].second) {
				d[G[tmp.id][i].first] = d[tmp.id] + G[tmp.id][i].second;
				nodes.push(node(G[tmp.id][i].first, d[G[tmp.id][i].first]));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", i, d[i]);
	}
	return 0;
}
