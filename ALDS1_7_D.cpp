#include <cstdio>
using namespace std;
int pre[105],in[105];
int pos=-1;
void rec (int l,int r) {
	if (l>=r) return;
	int cur=pre[++pos],cpos=l;
	while (in[cpos]!=cur) cpos++;
	rec (l,cpos);
	rec (cpos+1,r);
	printf ("%d",cur);
	if (cur!=pre[0]) printf (" ");
	else printf ("\n");
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&pre[i]);
	}
	for (int i=0;i<n;i++) {
		scanf ("%d",&in[i]);
	}
	rec(0,n);
    return 0;
}
