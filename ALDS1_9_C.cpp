#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2e6 + 7;
int n = 0;
char s[10];
int h[MAXN];
void maxHeapify(int cur) {
	int l = (cur << 1) + 1, r = l + 1, mx = cur;
	if (l < n && h[l] > h[mx]) mx = l;
	if (r < n && h[r] > h[mx]) mx = r;
	if (mx != cur) {
		swap (h[cur], h[mx]);
		maxHeapify(mx);
	}
}
int main() {
    while (1) {
    	scanf("%s", s);
    	if (s[0] == 'i') {
    		scanf("%d", &h[n++]);
    		for (int i = n - 1; i && h[((i - 1) >> 1)] < h[i]; i = (i - 1) >> 1) {
    			swap(h[((i - 1) >> 1)], h[i]);
			}
		}
		else if (s[1] == 'x') {
			printf("%d\n", h[0]);
			h[0] = h[--n];
			maxHeapify(0);
		}
		else return 0;
	}
}
