#include <stdio.h>
#include <stdlib.h>

struct Task {
	int low, high;
};

struct stack{
	struct Task *t;
	int cap; 
	int top;
};

void swap(int *a, int i, int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int partition(int *a, int low, int high)
{
	int i=low;
	int j=low;
	int temp;
	while(j<high){
		if (a[j]<a[high]){
			swap(a, i, j);
			i++;
		}
		j++;
	}
	swap(a, i, high);
	return i;
}

void push(struct stack *s, int low, int high)
{
	s->t[s->top].low=low;
	s->t[s->top].high=high;
	s->top++;
}

struct Task pop(struct stack *s)
{
	struct Task temp;
	s->top--;
	temp.low=s->t[s->top].low;
	temp.high=s->t[s->top].high;
	return temp;
}

void quicksort(int *a, int low, int high)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->cap=256;
	s->top=0;
	s->t=(struct Task*)malloc(256*sizeof(struct Task));
	push(s, low, high);
	
	while (s->top>0){
		struct Task now;
		now=pop(s);
		if (now.low<now.high){
			int i=partition(a, now.low, now.high);
			if (i-now.low>now.high-i){
				push(s, now.low, i-1);
				push(s, i+1, now.high);
			}
			else{
				push(s, i+1, now.high);
				push(s, now.low, i-1);
			}
		}	
	}
	free(s->t);
	free(s);	
}



int main (int argc, char **argv)
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	quicksort(a, 0, n-1);
	
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
