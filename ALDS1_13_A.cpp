#include <cstdio>
using namespace std;
char G[8][8];
bool row[8], col[8], dpos[15], dneg[15];
void dfs(int cur) {
	if (cur == 8) {
		for (int i = 0; i < 8; i++) {
	    	for (int j = 0; j < 8; j++) {
	    		putchar(G[i][j]);
			}
			putchar('\n');
		}
	}
	else {
		if (row[cur]) dfs(cur + 1);
		else {
			for (int i = 0; i < 8; i++) {
				if (!col[i] && !dpos[i + cur] && !dneg[cur - i + 7]) {
					row[cur] = true;
					col[i] = true;
					dpos[i + cur] = true;
					dneg[cur - i + 7] = true;
					G[cur][i] = 'Q';
					dfs(cur + 1);
					row[cur] = false;
					col[i] = false;
					dpos[i + cur] = false;
					dneg[cur - i + 7] = false;
					G[cur][i] = '.';
				}
			}
		}
	}
}
int main() {
    for (int i = 0; i < 8; i++) {
    	for (int j = 0; j < 8; j++) {
    		G[i][j] = '.';
		}
	}
	int k;
	scanf("%d", &k);
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = 'Q';
		row[x] = true;
		col[y] = true;
		dpos[x + y] = true;
		dneg[x - y + 7] = true;
	}
	dfs(0);
	return 0;
}
