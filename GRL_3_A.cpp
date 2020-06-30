#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 7;
int tim = 1;
int prenum[MAXN], p[MAXN], lowest[MAXN];
vector <int> G[MAXN];
set <int> ans;
void dfs(int cur) {
	prenum[cur] = tim;
	lowest[cur] = tim;
	tim++;
	for (int i = 0; i < G[cur].size(); i++) {
		if (prenum[G[cur][i]] == 0) {
			p[G[cur][i]] = cur;
			dfs(G[cur][i]);
			lowest[cur] = min(lowest[cur], lowest[G[cur][i]]);
		}
		else if (G[cur][i] != p[cur]) lowest[cur] = min(lowest[cur], prenum[G[cur][i]]);
	}
}
int main() {
    int v, e;
    scanf("%d%d", &v, &e);
    while (e--) {
    	int s, t;
    	scanf("%d%d", &s, &t);
    	G[s].push_back(t);
    	G[t].push_back(s);
	}
	dfs(0);
	int cnt = 0;
	for (int i = 1; i < v; i++) {
		if (p[i] == 0) cnt++;
		else if (prenum[p[i]] <= lowest[i]) ans.insert(p[i]);
	}
	if (cnt > 1) ans.insert(0);
	for (set <int> :: iterator i = ans.begin(); i != ans.end(); ++i) {
		printf("%d\n", *i);
	}
	return 0;
}
