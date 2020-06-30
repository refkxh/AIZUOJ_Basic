#include <cstdio>
using namespace std;
const int MAXN = 1e4 + 7;
int p[MAXN], rank[MAXN];
int find(int x) {
	return p[x] == x ? x : (p[x] = find(p[x]));
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
    	p[i] = i;
	}
	while (q--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op) {
			if (find(x) == find(y)) printf("1\n");
			else printf("0\n");
		}
		else {
			int px = find(x), py = find(y);
			if (rank[px] > rank[py]) p[py] = px;
			else if (rank[px] < rank[py]) p[px] = py;
			else {
				p[py] = px;
				rank[px]++;
			}
		}
	}
	return 0;
}
