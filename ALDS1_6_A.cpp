#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=2e6+7;
int a[MAXN],b[MAXN],cnt[10005];
int main () {
	int n,mx=0;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf ("%d",&a[i]);
		cnt[a[i]]++;
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=mx;i++) {
		cnt[i]+=cnt[i-1];
	}
	for (int i=n;i>0;i--) {
		b[cnt[a[i]]]=a[i];
		cnt[a[i]]--;
	}
	printf ("%d",b[1]);
	for (int i=2;i<=n;i++) {
		printf (" %d",b[i]);
	}
	printf ("\n");
    return 0;
}
