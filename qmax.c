#include <stdio.h>
#include <stdlib.h>

struct stack
{
	long count;
	long tail1;
	long tail2;
	long cap;
	long *stack1;
	long *stack2;
	long *max1;
	long *max2;
};

long maxelem (long a, long b)
{
	return (a>b)?a:b;
}

void max(struct stack *q)
{
	if (q->tail1!=0 && q->tail2!=q->cap){
		printf("%ld\n", maxelem(q->max1[q->tail1-1], q->max2[q->tail2+1]));
		return;
	}
	if (q->tail1!=0){
		printf("%ld\n", q->max1[q->tail1-1]);
		return;
	}
	printf("%ld\n", q->max2[q->tail2+1]);
}

void enq(struct stack *q, long x)
{
	q->stack1[q->tail1]=x;
	if (q->tail1==0)
		q->max1[q->tail1]=x;
	else
		q->max1[q->tail1]=maxelem(x, q->max1[q->tail1-1]);
	q->tail1++;
	q->count++;
}

void deq(struct stack *q)
{
	if (q->tail2==q->cap)
		while (q->tail1>0){
			q->tail1--;
			q->stack2[q->tail2]=q->stack1[q->tail1];
			if (q->tail2==q->cap)
				q->max2[q->tail2]=q->stack2[q->tail2];
			else
				q->max2[q->tail2]=maxelem(q->max2[q->tail2+1], q->stack2[q->tail2]);
			q->tail2--;
		}
	q->tail2++;
	printf("%ld\n", q->stack2[q->tail2]);
	q->count--;
}

void empty(struct stack *q)
{
	if (q->count==0)
		printf("true\n");
	else
		printf("false\n");
}

int main (int argc, char **argv)
{
	long i, n, j;
	scanf("%ld", &n);
	
	struct stack q;
	struct stack *qq=&q;
	qq->stack1=malloc(100000*sizeof(long));
	qq->stack2=malloc(100000*sizeof(long));
	qq->max1=malloc(100000*sizeof(long));
	qq->max2=malloc(100000*sizeof(long));
	q.count=0;
	q.tail1=0;
	q.cap=99999;
	q.tail2=99999;
	
	for (i=0; i<n; i++){
		char op[7];
		scanf("%s", op);
		if (op[0]=='E' && op[1]=='N'){
			long x;
			scanf("%ld", &x);
			enq(&q, x);
			continue;
		}
		if (op[0]=='D' && op[1]=='E'){
			deq(&q);
			continue;
			
		}
		
		if (op[0]=='M' && op[1]=='A'){
			max(&q);
			continue;
		}
		
		if (op[0]=='E' && op[1]=='M'){
			empty(&q);
			continue;
		}
	}
	free(qq->stack1);
	free(qq->stack2);
	free(qq->max1);
	free(qq->max2);	
	return 0;
}
