#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN]; 
int main () {
    int n,cnt=0,pos=0;
    scanf ("%d",&n);
    for (int i=0;i<n;i++) {
    	scanf ("%d",&a[i]);
	}
	bool flag=true;
	while (flag) {
		flag=false;
		for (int i=n-1;i>pos;i--) {
			if (a[i]<a[i-1]) {
				swap(a[i],a[i-1]);
				cnt++;
				flag=true;
			}
		}
		pos++;
	}
	printf ("%d",a[0]);
	for (int i=1;i<n;i++) {
		printf (" %d",a[i]);
	}
	printf ("\n%d\n",cnt);
    return 0;
}
