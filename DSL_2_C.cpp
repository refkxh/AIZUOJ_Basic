#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 7;
int sx, sy, tx, ty, anscnt, nodecnt = 0;
int ans[MAXN];
struct point {
	int id, x, y;
} p[MAXN];
struct node {
	int pos, l, r;
} nodes[MAXN];
bool cmpx(point p1, point p2) {
	return p1.x < p2.x;
}
bool cmpy(point p1, point p2) {
	return p1.y < p2.y;
}
int make2D(int l, int r, int dep) {
	if (l >= r) return -1;
	int mid = (l + r) >> 1, cur = nodecnt++;
	if (dep % 2) sort(p + l, p + r, cmpy);
	else sort(p + l, p + r, cmpx);
	nodes[cur].pos = mid;
	nodes[cur].l = make2D(l, mid, dep + 1);
	nodes[cur].r = make2D(mid + 1, r, dep + 1);
	return cur;
}
void find(int cur, int dep) {
	int x = p[nodes[cur].pos].x, y = p[nodes[cur].pos].y;
	if (sx <= x && x <= tx && sy <= y && y <= ty) ans[anscnt++] = p[nodes[cur].pos].id;
	if (dep % 2) {
		if (nodes[cur].l != -1 && sy <= y) find(nodes[cur].l, dep + 1);
		if (nodes[cur].r != -1 && y <= ty) find(nodes[cur].r, dep + 1);
	}
	else {
		if (nodes[cur].l != -1 && sx <= x) find(nodes[cur].l, dep + 1);
		if (nodes[cur].r != -1 && x <= tx) find(nodes[cur].r, dep + 1);
	}
}
int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	p[i].id = i;
    	scanf("%d%d", &p[i].x, &p[i].y);
	}
	int root = make2D(0, n, 0);
	scanf("%d", &q);
	while (q--) {
		anscnt = 0;
		scanf("%d%d%d%d", &sx, &tx, &sy, &ty);
		find(root, 0);
		sort(ans, ans + anscnt);
		for (int i = 0; i < anscnt; i++) {
			printf("%d\n", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}
