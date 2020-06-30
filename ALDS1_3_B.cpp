#include <cstdio>
#include <queue> 
using namespace std;
const int MAXN=1e5+7;
char nam[MAXN][15];
int tim[MAXN];
queue<int> qu;
int main () {
	int n,q,cnt=0;
	scanf ("%d%d",&n,&q);
	for (int i=0;i<n;i++) {
		scanf ("%s%d",nam[i],&tim[i]);
		qu.push(i);
	}
	while (!qu.empty()) {
		int cur=qu.front();
		qu.pop();
		if (tim[cur]>q) {
			qu.push(cur);
			tim[cur]-=q;
			cnt+=q;
		} else {
			cnt+=tim[cur];
			printf ("%s %d\n",nam[cur],cnt);
		}
	}
    return 0;
}
