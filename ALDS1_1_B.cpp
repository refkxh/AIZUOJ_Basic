#include <cstdio>
using namespace std;
int main() {
    int x, y, r;
    scanf("%d%d", &x, &y);
    while (y > 0) {
    	r = x % y;
    	x = y;
    	y = r;
	}
	printf("%d\n", x);
	return 0;
}
