#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 7;
int col = 1;
int idx[MAXN];
vector<int> G[MAXN];
void dfs(int cur) {
	idx[cur] = col;
	for (int i = 0; i < G[cur].size(); i++) {
		if (!idx[G[cur][i]]) dfs(G[cur][i]);
	}
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
    	int s, t;
    	scanf("%d%d", &s, &t);
    	G[s].push_back(t);
    	G[t].push_back(s);
	}
	for (int i = 0; i < n; i++) {
		if (!idx[i]) {
			dfs(i);
			col++;
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		if (idx[s] == idx[t]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
