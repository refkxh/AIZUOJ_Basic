#include <cstdio>
using namespace std;
int h[300]; 
int main () {
    int n;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) {
    	scanf ("%d",&h[i]);
	}
	for (int i=1;i<=n;i++) {
		printf ("node %d: key = %d, ",i,h[i]);
		if ((i>>1)) printf ("parent key = %d, ",h[i>>1]);
		if ((i<<1)<=n) printf ("left key = %d, ",h[i<<1]);
		if ((i<<1)+1<=n) printf ("right key = %d, ",h[(i<<1)+1]);
		printf ("\n");
	}
    return 0;
}
