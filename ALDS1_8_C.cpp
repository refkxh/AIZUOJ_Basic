#include <cstdio>
#include <cstdlib>
using namespace std;
char s[10];
struct node {
	int key;
	node *p,*left,*right;
};
node *NIL,*root=NIL;
void ins (int key) {
	node *p=NIL,*cur=root,*n=(node *)malloc(sizeof(node));
	n->key=key;
	n->left=NIL;
	n->right=NIL;
	while (cur!=NIL) {
		p=cur;
		if (key<cur->key) cur=cur->left;
		else cur=cur->right;
	}
	n->p=p;
	if (p==NIL) root=n;
	else if (key<p->key) p->left=n;
	else p->right=n;
}
node* find (int key,node *cur) {
	while (cur!=NIL&&cur->key!=key) {
		if (key<cur->key) cur=cur->left;
		else cur=cur->right;
	}
	return cur;
}
node* getSuccessor (node *u) {
	if (u->right!=NIL) {
		node *x=u->right;
		while (x->left!=NIL) x=x->left;
		return x;
	}
	node *p=u->p;
	while (p!=NIL&&u==p->right) {
		u=p;
		p=p->p;
	}
	return p;
}
void delNode (node *u) {
	node *del,*son;
	if (u->left==NIL||u->right==NIL) del=u;
	else del=getSuccessor (u);
	u->key=del->key;
	if (del->left!=NIL) son=del->left;
	else son=del->right;
	if (son!=NIL) son->p=del->p;
	if (del==root) root=son;
	else if (del==del->p->left) del->p->left=son;
	else del->p->right=son;
	free (del);
}
void preOrder (node *u) {
	if (u==NIL) return;
	printf (" %d",u->key);
	preOrder (u->left);
	preOrder (u->right);
}
void inOrder (node *u) {
	if (u==NIL) return;
	inOrder (u->left);
	printf (" %d",u->key);
	inOrder (u->right);
}
int main () {
	int m;
	scanf ("%d",&m);
	for (int i=0;i<m;i++) {
		scanf ("%s",s);
		if (s[0]=='i') {
			int key;
			scanf ("%d",&key);
			ins (key);
		} else if (s[0]=='f') {
			int key;
			scanf ("%d",&key);
			if (find (key,root)!=NIL) printf ("yes\n");
			else printf ("no\n");
		} else if (s[0]=='d') {
			int key;
			scanf ("%d",&key);
			delNode (find (key,root));
		} else {
			inOrder (root);
			printf ("\n");
			preOrder (root);
			printf ("\n");
		}
	}
    return 0;
}
