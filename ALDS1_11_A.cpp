#include <cstdio>
using namespace std;
int G[107][107];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	int id, cnt;
    	scanf("%d%d", &id, &cnt);
    	for (int j = 0; j < cnt; j++) {
    		int tmp;
    		scanf("%d", &tmp);
    		G[id][tmp] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", G[i][1]);
		for (int j = 2; j <= n; j++) {
			printf(" %d", G[i][j]);
		}
		putchar('\n');
	}
    return 0;
}
