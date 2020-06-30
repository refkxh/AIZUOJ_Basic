#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=1e5+7;
int p[MAXN],dep[MAXN]; 
vector<int> son[MAXN];
void dfs (int cur,int d) {
	dep[cur]=d;
	for (int i=0;i<son[cur].size();i++) {
		dfs (son[cur][i],d+1);
	}
}
int main () {
	int n;
	scanf ("%d",&n);
	memset (p,-1,sizeof(p));
	for (int i=0;i<n;i++) {
		int id,k;
		scanf ("%d%d",&id,&k);
		for (int j=0;j<k;j++) {
			int tmp;
			scanf ("%d",&tmp);
			son[id].push_back(tmp);
			p[tmp]=id;
		}
	}
	for (int i=0;i<n;i++) {
		if (p[i]==-1) {
			dfs (i,0);
			break;
		}
	}
	for (int i=0;i<n;i++) {
		printf ("node %d: parent = %d, depth = %d, ",i,p[i],dep[i]);
		if (p[i]==-1) printf ("root, [");
		else if (son[i].empty()) printf ("leaf, [");
		else printf ("internal node, [");
		for (int j=0;j<son[i].size();j++) {
			if (j>0) printf (", ");
			printf ("%d",son[i][j]);
		}
		printf ("]\n");
	}
    return 0;
}
