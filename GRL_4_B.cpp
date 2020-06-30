#include <cstdio>
#include <vector>
using namespace std;
const int MAXV = 1e4 + 7, MAXE = 1e5 + 7;
int anspos;
bool vis[MAXV];
int ans[MAXE];
vector <int> G[MAXV];
void dfs(int cur) {
	vis[cur] = true;
	for (int i = 0; i < G[cur].size(); i++) {
		if (!vis[G[cur][i]]) dfs(G[cur][i]);
	}
	ans[--anspos] = cur;
}
int main() {
    int v, e;
    scanf("%d%d", &v, &e);
    anspos = v;
    while (e--) {
    	int s, t;
    	scanf("%d%d", &s, &t);
    	G[s].push_back(t);
	}
	for (int i = 0; i < v; i++) {
		if (!vis[i]) dfs(i);
	}
	for (int i = 0; i < v; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
