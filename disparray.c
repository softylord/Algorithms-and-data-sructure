#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
        struct Elem *next;
        long v;
        long number;
};

void initht(long m, struct Elem **ht)
{
	long i;
	for (i=0; i<m; i++){
		ht[i]=(struct Elem*)malloc(sizeof(struct Elem));
		ht[i]->next=NULL;
		ht[i]->number=-1;
	}
}

void at(long i, long m, struct Elem **ht)
{
	long n=i%m;
	struct Elem *p;
	p=ht[n];
	while (p->next!=NULL){
		if (p->number==i){
			printf("%ld\n", p->v);
			return;
		}
		else 
			p=p->next;
	}
	if (p->number==i){
		printf("%ld\n", p->v);
		return;
	}
	printf("%d\n", 0);
}

void insert(long i, long v, long m, struct Elem **ht)
{
	long n=i%m;
	struct Elem *p;
	p=ht[n];
	while (p->next!=NULL){
		if (p->number==i){
			p->v=v;
			return;
		}
		p=p->next;
	}
	if (p->number==i){
		p->v=v;
		return;
	}
	p->next=(struct Elem*)malloc(sizeof(struct Elem));
	p->next->next=NULL;
	p->next->v=v;
	p->next->number=i;
}

void delete (long m, struct Elem **ht)
{
	long i;
	struct Elem *p, *q;
	for (i=0; i<m; i++) {
		p=ht[i];
		while (p->next!=NULL) {
			q=p->next;
			free(p);
			p = q;
		}
		free(p);
	}
}

int main (int argc, char **argv)
{
	long i, n, m, q, v;
	scanf("%ld %ld", &n, &m);
	struct Elem *ht[m];
	initht(m, ht);
	for (i=0; i<n; i++){
		char op[10];
		scanf("%s", op);
		if (op[1]=='T'){
			scanf("%ld", &q);
			at(q, m, ht);
			continue;
		}
		else{
			scanf("%ld %ld", &q, &v);
			insert(q, v, m, ht);
			continue;
		}
	}
	delete(m, ht);
	return 0;
}
