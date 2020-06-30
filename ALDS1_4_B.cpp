#include <cstdio>
using namespace std;
int s[100005];
int n;
bool find (int x) {
	int l=0,r=n,mid;
	while (r-l>1) {
		mid=(l+r)>>1;
		if (s[mid]==x) return true;
		else if (s[mid]>x) r=mid;
		else l=mid+1;
	}
	if (s[l]==x&&l!=r) return true;
	return false;
}
int main () {
	int q,cnt=0;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&s[i]);
	}
	scanf ("%d",&q);
	for (int i=0;i<q;i++) {
		int tmp;
		scanf ("%d",&tmp);
		if (find(tmp)) cnt++;
	}
	printf ("%d\n",cnt);
    return 0;
}
