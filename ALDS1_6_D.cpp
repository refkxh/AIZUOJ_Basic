#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],b[1005],to[10005];
bool vis[1005];
int main () {
	int n,ans=0;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&a[i]);
		b[i]=a[i];
	}
	sort (b,b+n);
	for (int i=0;i<n;i++) {
		to[b[i]]=i;
	}
	for (int i=0;i<n;i++) {
		if (vis[i]) continue;
		int pos=i,sum=0,mn=1e4+7,cnt=0;
		while (!vis[pos]) {
			vis[pos]=true;
			sum+=a[pos];
			mn=min(mn,a[pos]);
			cnt++;
			pos=to[a[pos]];
		}
		ans+=min(sum+(cnt-2)*mn,sum+mn+(cnt+1)*b[0]);
	}
	printf ("%d\n",ans);
    return 0;
}
