#include <cstdio>
using namespace std;
const int MAXN=1e6+7;
int n,cnt=0;
int a[MAXN],g[105],h[105];
void is (int g) {
	for (int i=g;i<n;i++) {
		int v=a[i],j=i-g;
		while (j>=0&&a[j]>v) {
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g]=v;
	}
}
int main () {
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&a[i]); 
	}
	int m=1;
	h[1]=1;
	while (h[m]<n) h[++m]=3*h[m-1]+1;
	if (h[m]>n) m--;
	for (int i=1;i<=m;i++) {
		g[i]=h[m+1-i];
	}
	for (int i=1;i<=m;i++) {
		is (g[i]);
	}
	printf ("%d\n%d",m,g[1]);
	for (int i=2;i<=m;i++) {
		printf (" %d",g[i]);
	}
	printf ("\n%d\n",cnt);
	for (int i=0;i<n;i++) {
		printf ("%d\n",a[i]);
	}
    return 0;
}
