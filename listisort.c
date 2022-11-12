#include <stdio.h>
#include <stdlib.h>

struct Elem {
	struct Elem *prev, *next;
	int v;
};

struct Elem *initlist()
{
	struct Elem *a=(struct Elem*)malloc(sizeof(struct Elem));
	a->prev=a;
	a->next=a;
	return a;
}

void insert(struct Elem *x, struct Elem *y)
{
	struct Elem *z;
	z=x->next;
	x->next=y;
	y->prev=x;
	y->next=z;
	z->prev=y;
}

void delete(struct Elem *x)
{
	struct Elem *y, *z;
	y=x->prev;
	z=x->next;
	y->next=z;
	z->prev=y;
	x->prev=x->next=NULL;
}

void insertsort(struct Elem *a)
{
	struct Elem *i, *loc;
	i=a->next;
	while (i!=a){
		loc=i->prev;
		while (loc!=a && (loc->v)>(i->v))
			loc=loc->prev;
		delete(i);
		insert(loc, i);
		i=i->next;
	}
}

int main (int argc, char **argv)
{
	int n, i, j;
	scanf("%d", &n);
	struct Elem *list=initlist();
	struct Elem *a, *temp;
	for (i=0; i<n; i++){
		a=initlist();
		scanf("%d", &a->v);
		insert(list, a);
	}
	insertsort(list);
	a=list->next;
	while (a!=list){
		printf("%d ", a->v);
		a=a->next;
	}
	printf("\n");
	a=list->next;
	while (a!=list){
		temp=a->next;
		free(a);
		a=temp;
	}
	free(list);
	return 0;
}
