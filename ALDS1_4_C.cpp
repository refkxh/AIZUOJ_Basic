#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=7e8;
bool b[MAXN];
char c[15];
int f () {
	int len=strlen(c),ret=0;
	for (int i=0;i<len;i++) {
		ret*=5;
		ret++;
		switch (c[i]) {
			case 'C':
				ret++;
			case 'G':
				ret++;
			case 'T':
				ret++;
		}
	}
	return ret;
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		scanf ("%s",c);
		if (c[0]=='i') {
			scanf ("%s",c);
			b[f()]=true;
		} else {
			scanf ("%s",c);
			if (b[f()]) printf ("yes\n");
			else printf ("no\n");
		}
	}
    return 0;
}
