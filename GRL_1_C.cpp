#include <cstdio>
#include <algorithm>
using namespace std;
const long long INF = (long long) 1 << 62;
long long G[107][107];
int main() {
    int v, e;
    scanf("%d%d", &v, &e);
    for (int i = 0; i < v; i++) {
    	for (int j = 0; j < v; j++) {
    		if (i != j) G[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		int from, to, w;
		scanf("%d%d%d", &from, &to, &w);
		G[from][to] = w;
	}
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (G[i][k] < INF && G[k][j] < INF) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	for (int i = 0; i < v; i++) {
		if (G[i][i] < 0) {
			printf("NEGATIVE CYCLE\n");
			return 0;
		}
	}
	for (int i = 0; i < v; i++) {
		if (G[i][0] >= INF) printf("INF");
    	else printf("%lld", G[i][0]);
    	for (int j = 1; j < v; j++) {
    		if (G[i][j] >= INF) printf(" INF");
    		else printf(" %lld", G[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
