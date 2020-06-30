#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=40;
int n;
struct card {
	char letter;
	int num;
} c[MAXN],d[MAXN];
void bs () {
	int pos=0;
	bool flag=true;
	while (flag) {
		flag=false;
		for (int i=n-1;i>pos;i--) {
			if (c[i].num<c[i-1].num) {
				swap(c[i],c[i-1]);
				flag=true;
			}
		}
		pos++;
	}
}
void ss () {
	for (int i=0;i<n;i++) {
		int mn=i;
		for (int j=i+1;j<n;j++) {
			if (d[j].num<d[mn].num) mn=j;
		}
		if (mn!=i) swap (d[mn],d[i]);
	}
}
int main () {
	scanf ("%d",&n);
	getchar();
	scanf ("%c%d",&c[0].letter,&c[0].num);
	d[0]=c[0];
	for (int i=1;i<n;i++) {
		scanf (" %c%d",&c[i].letter,&c[i].num);
		d[i]=c[i];
	}
	bs();
	ss();
	printf ("%c%d",c[0].letter,c[0].num);
	for (int i=1;i<n;i++) {
		printf (" %c%d",c[i].letter,c[i].num);
	}
	printf ("\nStable\n");
	bool flag=true;
	printf ("%c%d",d[0].letter,d[0].num);
	if (d[0].letter!=c[0].letter) flag=false;
	for (int i=1;i<n;i++) {
		printf (" %c%d",d[i].letter,d[i].num);
		if (d[i].letter!=c[i].letter) flag=false;
	}
	if (flag) printf ("\nStable\n");
	else printf ("\nNot stable\n");
    return 0;
}
