#include <cstdio>
#include <algorithm>
using namespace std;
int b[1407][1407], dp[1407][1407];
int main() {
    int h, w, maxa = 0;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
    	for (int j = 1; j <= w; j++) {
    		scanf("%d", &b[i][j]);
		}
	}
	for (int i = 1; i <= h; i++) {
    	for (int j = 1; j <= w; j++) {
    		if (b[i][j] == 1) dp[i][j] = 0;
			else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				maxa = max(maxa, dp[i][j]);
			}
		}
	}
	printf("%d\n", maxa * maxa);
	return 0;
}
