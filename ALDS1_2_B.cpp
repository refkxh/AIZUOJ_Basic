#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN]; 
int main () {
    int n,cnt=0;
    scanf ("%d",&n);
    for (int i=0;i<n;i++) {
    	scanf ("%d",&a[i]);
	}
	for (int i=0;i<n;i++) {
		int mn=i;
		for (int j=i+1;j<n;j++) {
			if (a[j]<a[mn]) mn=j;
		}
		if (mn!=i) {
			swap (a[mn],a[i]);
			cnt++;
		}
	}
	printf ("%d",a[0]);
	for (int i=1;i<n;i++) {
		printf (" %d",a[i]);
	}
	printf ("\n%d\n",cnt);
    return 0;
}
