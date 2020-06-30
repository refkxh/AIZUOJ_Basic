#include <cstdio>
using namespace std;
unsigned long long fib[45];
int main() {
    fib[0] = 1;
    fib[1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
    	fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("%lld\n", fib[n]);
    return 0;
}
