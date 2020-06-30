#include <cstdio>
#include <stack>
using namespace std;
const int MAXN=2e4+7;
char c[MAXN];
stack<int> s1,s3;
stack<pair<int,int> > s2;
int main () {
	scanf ("%s",c);
	int a=0,k=0,cur=0;
	while (c[cur]!='\0') {
		if (c[cur]=='\\') s1.push(cur);
		if (c[cur]=='/'&&!s1.empty()) {
			int tmp=s1.top(),stmp=0;
			s1.pop();
			a+=cur-tmp;
			while (!s2.empty()) {
				int i=s2.top().first,j=s2.top().second;
				if (i<tmp) break;
				s2.pop();
				stmp+=j;
			}
			s2.push(make_pair(tmp,cur-tmp+stmp));
		}
		cur++;
	}
	while (!s2.empty()) {
		s3.push(s2.top().second);
		s2.pop();
		k++;
	}
	printf ("%d\n%d",a,k);
	while (!s3.empty()) {
		printf (" %d",s3.top());
		s3.pop();
	}
	printf ("\n");
    return 0;
}
