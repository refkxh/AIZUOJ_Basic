#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct card {
	char c;
	int num;
	card (char c,int num) :c(c),num(num) {}
	bool operator < (const card &rhs) const {
		return num<rhs.num;
	}
	bool operator == (const card &rhs) const {
		return num==rhs.num&&c==rhs.c;
	}
};
vector<card> a,b;
int part (int l,int r) {
	int i=l-1;
	for (int j=l;j<r;j++) {
		if (a[j].num<=a[r].num) swap (a[++i],a[j]);
	}
	swap (a[++i],a[r]);
	return i;
}
void quickSort (int l,int r) {
	if (l<r) {
		int mid=part(l,r);
		quickSort(l,mid-1);
		quickSort(mid+1,r);
	}
}
int main () {
	int n;
	scanf ("%d",&n);
	a.push_back(card(0,0));
	for (int i=0;i<n;i++) {
		getchar();
		char c;
		int num;
		scanf ("%c %d",&c,&num);
		a.push_back(card(c,num));
	}
	b=a;
	quickSort (1,n);
	stable_sort (++b.begin(),b.end());
	if (a==b) printf ("Stable\n");
	else printf ("Not stable\n");
	for (int i=1;i<=n;i++) {
		printf ("%c %d\n",a[i].c,a[i].num);
	}
    return 0;
}
