#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
	long int key, count;
	char word[10];
	struct tree *parent, *left, *right;
} *root;

struct tree *inittree(long k, char *v, long q, struct tree **arr)
{
	struct tree *a=malloc(sizeof(struct tree));
	a->parent=a->left=a->right=NULL;
	a->count=1;
	a->key=k;
	arr[q]=a;
	strcpy(a->word, v);
	return a;
}

struct tree *insert(struct tree *t, long k, char *v, long q, struct tree **arr)
{
	if (t==NULL)
		return inittree(k, v, q, arr);
	if (k<t->key)
		t->left=insert(t->left, k, v, q, arr);
	else if(k>t->key)
		t->right=insert(t->right, k, v, q, arr);
	else
		strcpy(t->word, v);
	t->count=1;
	if (t->left!=NULL) 
		t->count+=t->left->count; 
	if (t->right!=NULL) 
		t->count+=t->right->count; 
	return t;
}

struct tree *recsearch(struct tree *t, long k)
{
	long a;
	if (t->left==NULL)
		a=0;
	else 
		a=t->left->count;
	if (a>k)
		return recsearch(t->left, k);
	else if (a<k)
		return recsearch(t->right, k);
	else 
		return t;
}

void search(struct tree *t, long k)
{
	/*struct tree *a=recsearch(t, k);
	printf("%s\n", a->word);*/
	struct tree *x=recsearch(t, k);
	printf("%s\n", x->word);
}

void lookup(struct tree *t, long k)
{
	struct tree *x=t;
	while (x!=NULL && x->key!=k){
		if (k<x->key)
			x=x->left;
		else 
			x=x->right;
	}
	printf("%s\n", x->word);
}

struct tree *mini(struct tree *t)
{
	struct tree *x;
	if (t==NULL)
		x=NULL;
	else{
		x=t;
		while (x->left!=NULL)
			x=x->left;
	}
	return x;
}

struct tree *deletemini(struct tree *t)
{
	if (t->left==NULL)
		return t->right;
	t->left=deletemini(t->left);
	t->count=1;
	if (t->left!=NULL) 
		t->count+=t->left->count; 
	if (t->right!=NULL) 
		t->count+=t->right->count; 
	return t;
}

struct tree *delete(struct tree *t, int k)
{
	struct tree *x=t;
	if (k<t->key)
		t->left=delete(t->left, k);
	else if(k>t->key)
		t->right=delete(t->right, k);
	else{
		if (t->right==NULL)
			return t->left;
		if (t->left==NULL)
			return t->right;
		t=mini(x->right);
		t->right=deletemini(x->right);
		t->left=x->left;
	}
	t->count=1;
	if (t->left!=NULL) 
		t->count+=t->left->count; 
	if (t->right!=NULL) 
		t->count+=t->right->count; 
	return t;
		
}

/*void fr(struct tree *t)
{
	if (t->left!=NULL)
		fr(t->left)
	if (t->right!=NULL)
		fr(t->right)
	free(t);
}*/

int main (int argc, char **argv)
{
	root=NULL;
	long int n, i, k, q=0;
	scanf("%ld", &n);
	struct tree *arr[n];
	char v[10];
	for (i=0; i<n; i++){
		char op[10];
		scanf("%s %ld", v, &k);
		if (v[0]=='I'){
			scanf("%s", v);
			root=insert(root, k, v, q, arr);
			q++;
			continue;
		}
		if (v[0]=='L'){
			lookup(root, k);
			continue;
		}
		if (v[0]=='D'){
			root=delete(root, k);
			continue;
		}
		if (v[0]=='S')
			search(root, k);
	}
	
	for (i=0; i<q; i++){
		root=arr[i];
		free(root);
	}
	return 0;
}
