#include <cstdio>
using namespace std;
int tim = 0;
bool vis[107];
int G[107][107], d[107], f[107];
void dfs(int cur) {
	vis[cur] = true;
	d[cur] = ++tim;
	for (int i = 0; G[cur][i]; i++) {
		if (!vis[G[cur][i]]) dfs(G[cur][i]);
	}
	f[cur] = ++tim;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	int u, k;
    	scanf("%d%d", &u, &k);
    	for (int j = 0; j < k; j++) {
    		scanf("%d", &G[u][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d %d\n", i, d[i], f[i]);
	}
    return 0;
}
