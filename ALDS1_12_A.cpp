#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool vis[107];
struct edge {
	int u, v, w;
	edge(int u, int v, int w) :u(u), v(v), w(w) {}
	bool operator < (const edge &rhs) const {
		return w < rhs.w;
	}
};
vector<edge> e;
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		int tmp;
    		scanf("%d", &tmp);
    		if (tmp >= 0 && i >= j) e.push_back(edge(i, j, tmp));
		}
	}
	sort(e.begin(), e.end());
	vis[e[0].u] = true;
	bool flag = true;
	int cnt = e.size();
	while (flag) {
		flag = false;
		for (int i = 0; i < cnt; i++) {
			if (vis[e[i].u] != vis[e[i].v]) {
				vis[e[i].u] = true;
				vis[e[i].v] = true;
				ans += e[i].w;
				flag = true;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
