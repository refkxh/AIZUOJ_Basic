#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=5e5+5;
int n;
int h[MAXN];
void maxHeapify (int cur) {
	int l=(cur<<1),r=l+1,mx=cur;
	if (l<=n&&h[l]>h[mx]) mx=l;
	if (r<=n&&h[r]>h[mx]) mx=r;
	if (mx!=cur) {
		swap (h[cur],h[mx]);
		maxHeapify (mx);
	}
}
int main () {
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) {
    	scanf ("%d",&h[i]);
	}
	for (int i=(n>>1);i>0;i--) {
		maxHeapify (i);
	}
	for (int i=1;i<=n;i++) {
		printf (" %d",h[i]);
	}
	printf ("\n");
    return 0;
}
