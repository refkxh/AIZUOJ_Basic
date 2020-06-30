#include <cstdio>
using namespace std;
int a[25];
int n;
bool judge (int m,int sum,int pos) {
	if (pos==n+1||sum>m) return false;
	if (sum==m) return true;
	return judge(m,sum,pos+1)||judge(m,sum+a[pos],pos+1);
}
int main () {
	int q;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&a[i]);
	}
	scanf ("%d",&q);
	for (int i=0;i<q;i++) {
		int m;
		scanf ("%d",&m);
		if (judge(m,0,0)) printf ("yes\n");
		else printf ("no\n");
	}
    return 0;
}
