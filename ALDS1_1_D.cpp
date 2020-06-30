#include <cstdio>
#include <algorithm>
using namespace std;
int main () {
    int n,mn=2e9+7,ans=-1e9-7;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		int tmp;
		scanf ("%d",&tmp);
		ans=max(ans,tmp-mn);
		mn=min(mn,tmp);
	}
	printf ("%d\n",ans);
    return 0;
}
