#include <cstdio>
using namespace std;
const int MAXN=1e5+7;
int w[MAXN];
int n,k;
bool check (int p) {
	int pos=0;
	for (int i=0;i<k;i++) {
		int cur=0;
		while (cur+w[pos]<=p) {
			cur+=w[pos++];
			if (pos==n) return true;
		}
	}
	return false;
}
int main () {
	int l=0,r=1e9,mid;
	scanf ("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf ("%d",&w[i]);
		if (w[i]>l) l=w[i];
	}
	while (r-l>=1) {
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf ("%d\n",l);
    return 0;
}
