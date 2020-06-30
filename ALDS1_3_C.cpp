#include <cstdio>
#include <cstdlib>
using namespace std;
char cmd[20];
struct node {
	int val;
	node *prev, *nxt;
};
node *nil;
void ins(int x) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->val = x;
	tmp->nxt = nil->nxt;
	tmp->prev = nil;
	nil->nxt->prev = tmp;
	nil->nxt = tmp;
}
node *find(int x) {
	node *cur = nil->nxt;
	while (cur != nil && cur->val != x) cur = cur->nxt;
	return cur;
}
void deleteNode(node *x) {
	if (x == nil) return;
	x->prev->nxt = x->nxt;
	x->nxt->prev = x->prev;
	free(x);
}
void deleteFirst() {
	deleteNode(nil->nxt);
}
void deleteLast() {
	deleteNode(nil->prev);
}
void deletex(int x) {
	deleteNode(find(x));
}
int main() {
	int n;
	scanf("%d", &n);
	nil = (node *)malloc(sizeof(node));
	nil->nxt = nil;
	nil->prev = nil;
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (cmd[0] == 'i') {
			int tmp;
			scanf("%d", &tmp);
			ins(tmp);
		}
		else if (cmd[6] == 'F') deleteFirst();
		else if (cmd[6] == 'L') deleteLast();
		else {
			int tmp;
			scanf("%d", &tmp);
			deletex(tmp);
		}
	}
	node *i = nil->nxt;
	if (i != nil) {
		printf("%d", i->val);
		i = i->nxt;
	}
	while (i != nil) {
		printf(" %d", i->val);
		i = i->nxt;
	}
	printf("\n");
	return 0;
}
