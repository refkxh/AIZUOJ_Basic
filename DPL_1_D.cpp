#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN], dp[MAXN]; 
int main() {
    int n, len;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
	}
	dp[0] = a[0];
	len = 1;
	for (int i = 1; i < n; i++) {
		if (dp[len - 1] < a[i]) dp[len++] = a[i];
		else *lower_bound(dp, dp + len, a[i]) = a[i];
	}
	printf("%d\n", len);
	return 0;
}
