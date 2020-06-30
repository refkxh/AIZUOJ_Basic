#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXW = 1e4 + 7;
int v[107], w[107], dp[2][MAXW];
int main() {
    int n, W;
	scanf("%d%d", &n, &W);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &v[i], &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (j >= w[i]) dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - w[i]] + v[i]);
			else dp[i % 2][j] = dp[(i - 1) % 2][j];
		}
	}
	printf("%d\n", dp[n % 2][W]);
	return 0;
}
