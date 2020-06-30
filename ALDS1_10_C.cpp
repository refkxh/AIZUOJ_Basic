#include <cstdio>
#include <algorithm>
using namespace std;
int m[107], dp[107][107];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &m[i], &m[i + 1]);
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = 1e9 + 7;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
    return 0;
}
