#include <cstdio>
using namespace std;
const int MOD = 1e9 + 7; 
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    long long ans = 1, cur = m;
    for (int i = 0; (1 << i) <= n; i++) {
    	if (n & (1 << i)) ans = (ans * cur) % MOD;
    	cur = (cur * cur) % MOD;
	}
    printf("%lld\n", ans);
	return 0;
}
