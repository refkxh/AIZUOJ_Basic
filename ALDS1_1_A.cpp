#include <cstdio>
using namespace std;
const int MAXN=105;
int a[MAXN]; 
int main () {
    int n;
    scanf ("%d",&n);
    for (int i=0;i<n;i++) {
    	scanf ("%d",&a[i]);
	}
	printf ("%d",a[0]);
	for (int i=1;i<n;i++) {
		printf (" %d",a[i]);
	}
	printf ("\n");
	for (int i=1;i<n;i++) {
		int v=a[i];
		int j=i-1;
		while (j>=0&&a[j]>v) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		printf ("%d",a[0]);
		for (int k=1;k<n;k++) {
			printf (" %d",a[k]);
		}
		printf ("\n");
	}
    return 0;
}
