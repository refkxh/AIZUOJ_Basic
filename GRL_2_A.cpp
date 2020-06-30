#include <cstdio>
#include <queue> 
using namespace std;
const int MAXV = 1e4 + 7;
struct edge {
	int u, v, w;
	edge(int u, int v, int w) :u(u), v(v), w(w) {}
	bool operator < (const edge& rhs) const {
		return w > rhs.w;
	}
};
int p[MAXV];
priority_queue<edge> q;
int find(int x) {
	return p[x] == x ? x : (p[x] = find(p[x]));
}
int main() {
    int v, e, ans = 0;
    scanf("%d%d", &v, &e);
    for (int i = 0; i < v; i++) {
    	p[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int s, t, w;
		scanf("%d%d%d", &s, &t, &w);
		q.push(edge(s, t, w));
	}
	while (!q.empty()) {
		edge cur = q.top();
		q.pop();
		int p1 = find(cur.u), p2 = find(cur.v);
		if (p1 != p2) {
			p[p2] = p1;
			ans += cur.w;
		}
	}
    printf("%d\n", ans);
	return 0;
}
