#include <cstdio>
using namespace std;
int s[10005];
int n;
bool find (int x) {
	for (int i=0;i<n;i++) {
		if (s[i]==x) return true;
	}
	return false;
}
int main () {
	int q,cnt=0;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&s[i]);
	}
	scanf ("%d",&q);
	for (int i=0;i<q;i++) {
		int tmp;
		scanf ("%d",&tmp);
		if (find(tmp)) cnt++;
	}
	printf ("%d\n",cnt);
    return 0;
}
