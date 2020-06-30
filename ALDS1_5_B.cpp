#include <cstdio>
using namespace std;
const int MAXN=5e5+7;
int s[MAXN],t[MAXN];
int cnt=0;
void merge (int l,int r,int mid) {
	int t1=l,t2=mid,pos=l;
	while (pos<r) {
		if (t2==r||(t1<mid&&s[t1]<s[t2])) t[pos++]=s[t1++];
		else t[pos++]=s[t2++];
		cnt++;
	}
	for (int i=l;i<r;i++) {
		s[i]=t[i];
	}
}
void mergeSort (int l,int r) {
	if (r-l<2) return;
	int mid=(l+r)>>1;
	mergeSort (l,mid);
	mergeSort (mid,r);
	merge (l,r,mid);
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&s[i]);
	}
	mergeSort (0,n);
	printf ("%d",s[0]);
	for (int i=1;i<n;i++) {
		printf (" %d",s[i]);
	}
	printf ("\n%d\n",cnt);
    return 0;
}
