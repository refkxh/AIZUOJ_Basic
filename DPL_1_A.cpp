#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 7;
int c[27], dp[MAXN];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    	scanf("%d", &c[i]);
	}
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
    	for (int j = c[i]; j <= n; j++) {
    		dp[j] = min(dp[j], dp[j - c[i]] + 1);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
