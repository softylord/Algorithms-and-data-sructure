#include <stdio.h>
#include <stdlib.h>

struct helper
{
    int pos;
    int value;
    int len;
    int num;
};

void heapify(struct helper *a, int i, int n)
{
	while (1){
		int left=2*i+1;
		int right=2*i+2;
		int j=i;
		if ((left<n) && (a[i].value>a[left].value))
			i=left;
		if ((right<n) && (a[i].value>a[right].value))
			i=right;
		if (i==j)
			break;
		struct helper temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
}


void buildheap(struct helper *a, int n)
{
	int i=(n/2)-1;
	while (i>=0){
		heapify(a, i, n);
		i--;
	}
	
}

int main (int argc, char **argv)
{
	int n, i, j;
	scanf("%d", &n);
	struct helper *a=(struct helper*)malloc(n*sizeof(struct helper));
	int max=0, size=0, count=n;
	for (i=0; i<n; i++){
		scanf("%d", &a[i].len);
		if (max<a[i].len)
			max=a[i].len;
		size+=a[i].len;
	}
	int arr[n][max];
	for (i=0; i<n; i++){
		a[i].pos=0;
		a[i].num=i;
		for (j=0; j<a[i].len; j++)
			scanf("%d", &arr[i][j]);
		if (a[i].len!=0)
			a[i].value=arr[i][0];
		else
			a[i].value=2147483647;
	}
	buildheap(a, n);
	for (i=0; i<size; i++){
		printf("%d ", a[0].value);
		if (a[0].pos!=a[0].len-1){
			a[0].pos++;
			a[0].value=arr[a[0].num][a[0].pos];
			heapify(a, 0, count);
		}
		else{
			count--;
			if (count!=0){
				a[0]=a[count];
				heapify(a, 0, count);
			}
		}
	}
	free(a);
	printf("\n");
	return 0;
}

