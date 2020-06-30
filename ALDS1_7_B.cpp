#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[30],left[30],right[30],s[30],dep[30],h[30],deg[30]; 
void setdep (int cur,int d) {
	dep[cur]=d;
	if (left[cur]!=-1) setdep (left[cur],d+1);
	if (right[cur]!=-1) setdep (right[cur],d+1);
}
int seth (int cur) {
	if (left[cur]!=-1) h[cur]=max(h[cur],seth(left[cur])+1);
	if (right[cur]!=-1) h[cur]=max(h[cur],seth(right[cur])+1);
	return h[cur];
}
int main () {
	int n;
	scanf ("%d",&n);
	memset (p,-1,sizeof(p));
	memset (left,-1,sizeof(left));
	memset (right,-1,sizeof(right));
	memset (s,-1,sizeof(s));
	for (int i=0;i<n;i++) {
		int id,l,r;
		scanf ("%d%d%d",&id,&l,&r);
		left[id]=l;
		right[id]=r;
		if (l!=-1) {
			deg[id]++;
			p[l]=id;
		}
		if (r!=-1) {
			deg[id]++;
			p[r]=id;
		}
		if (l!=-1&&r!=-1) {
			s[l]=r;
			s[r]=l;
		}
	}
	for (int i=0;i<n;i++) {
		if (p[i]==-1) {
			setdep (i,0);
			seth (i);
			break;
		}
	}
	for (int i=0;i<n;i++) {
		printf ("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,p[i],s[i],deg[i],dep[i],h[i]);
		if (p[i]==-1) printf ("root\n");
		else if (deg[i]==0) printf ("leaf\n");
		else printf ("internal node\n");
	}
    return 0;
}
