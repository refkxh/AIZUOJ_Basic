#include <cstdio>
using namespace std;
const int MAXN=2e5+7;
int s[MAXN],t[MAXN];
long long merge (int l,int r,int mid) {
	int t1=l,t2=mid,pos=l;
	long long ret=0;
	while (pos<r) {
		if (t2==r||(t1<mid&&s[t1]<s[t2])) t[pos++]=s[t1++];
		else {
			t[pos++]=s[t2++];
			ret+=mid-t1;
		}
	}
	for (int i=l;i<r;i++) {
		s[i]=t[i];
	}
	return ret;
}
long long mergeSort (int l,int r) {
	if (r-l<2) return 0;
	int mid=(l+r)>>1;
	long long ret=0;
	ret+=mergeSort (l,mid);
	ret+=mergeSort (mid,r);
	ret+=merge (l,r,mid);
	return ret;
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&s[i]);
	}
	printf ("%lld\n",mergeSort (0,n));
    return 0;
}
