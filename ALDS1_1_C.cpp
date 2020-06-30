#include <cstdio>
using namespace std;
bool isPrime(int x) {
	if (x == 2) return true;
	if (x == 1 || (x & 1) == 0) return false;
	for (int i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
    int n, ans = 0;
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		if (isPrime(x)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
