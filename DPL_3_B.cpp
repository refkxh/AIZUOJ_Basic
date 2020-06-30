#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int w;
int b[1407][1407], pre[1407][1407];
int solve(int height[]) {
	int ret = 0;
	stack<pair<int, int> > s;
	for (int i = 1; i <= w + 1; i++) {
		if (s.empty()) s.push(make_pair(height[i], i));
		else {
			if (s.top().first < height[i]) s.push(make_pair(height[i], i));
			else if (s.top().first > height[i]) {
				int pos = i;
				while (!s.empty() && s.top().first >= height[i]) {
					pair<int, int> cur = s.top();
					s.pop();
					int area = cur.first * (i - cur.second);
					ret = max(ret, area);
					pos = cur.second;
				}
				s.push(make_pair(height[i], pos));
			}
		}
	}
	return ret;
}
int main() {
    int h, ans = 0;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
    	for (int j = 1; j <= w; j++) {
    		scanf("%d", &b[i][j]);
		}
	}
	for (int i = 1; i <= h; i++) {
    	for (int j = 1; j <= w; j++) {
    		if (b[i][j] == 1) pre[i][j] = 0;
			else pre[i][j] = pre[i - 1][j] + 1;
		}
	}
	for (int i = 1; i <= h; i++) {
		ans = max(ans, solve(pre[i]));
	}
	printf("%d\n", ans);
	return 0;
}
