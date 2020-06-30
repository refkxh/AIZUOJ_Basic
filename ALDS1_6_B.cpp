#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int main () {
	int n;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf ("%d",&a[i]);
	}
	int i=0;
	for (int j=1;j<n;j++) {
		if (a[j]<=a[n]) swap (a[++i],a[j]);
	}
	swap (a[++i],a[n]);
	for (int j=1;j<=n;j++) {
		if (j>1) printf (" ");
		if (j==i) printf ("[%d]",a[j]);
		else printf ("%d",a[j]);
	}
	printf ("\n");
    return 0;
}
