#include <cstdio>
#include <cstring>
using namespace std;
int p[30],left[30],right[30];
void preParse (int cur) {
	printf (" %d",cur);
	if (left[cur]!=-1) preParse (left[cur]);
	if (right[cur]!=-1) preParse (right[cur]);
}
void inParse (int cur) {
	if (left[cur]!=-1) inParse (left[cur]);
	printf (" %d",cur);
	if (right[cur]!=-1) inParse (right[cur]);
}
void postParse (int cur) {
	if (left[cur]!=-1) postParse (left[cur]);
	if (right[cur]!=-1) postParse (right[cur]);
	printf (" %d",cur);
}
int main () {
	int n;
	scanf ("%d",&n);
	memset (p,-1,sizeof(p));
	memset (left,-1,sizeof(left));
	memset (right,-1,sizeof(right));
	for (int i=0;i<n;i++) {
		int id,l,r;
		scanf ("%d%d%d",&id,&l,&r);
		left[id]=l;
		right[id]=r;
		if (l!=-1) p[l]=id;
		if (r!=-1) p[r]=id;
	}
	for (int i=0;i<n;i++) {
		if (p[i]==-1) {
			printf ("Preorder\n");
			preParse (i);
			printf ("\nInorder\n");
			inParse (i);
			printf ("\nPostorder\n");
			postParse (i);
			printf ("\n");
			break;
		}
	}
    return 0;
}
