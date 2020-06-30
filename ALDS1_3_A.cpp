#include <cstdio>
#include <cstdlib>
#include <stack> 
using namespace std;
stack<int> s;
char a[10];
int main () {
	while (~scanf ("%s",a)) {
		if (a[0]=='+') {
			int tmp1,tmp2;
			tmp1=s.top();
			s.pop();
			tmp2=s.top();
			s.pop();
			s.push(tmp1+tmp2);
		} else if (a[0]=='-') {
			int tmp1,tmp2;
			tmp1=s.top();
			s.pop();
			tmp2=s.top();
			s.pop();
			s.push(tmp2-tmp1);
		} else if (a[0]=='*') {
			int tmp1,tmp2;
			tmp1=s.top();
			s.pop();
			tmp2=s.top();
			s.pop();
			s.push(tmp1*tmp2);
		} else s.push(atoi(a));
	}
	printf ("%d\n",s.top());
    return 0;
}
