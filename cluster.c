#include <stdio.h>
#include <stdlib.h>

struct time
{
	int start;
	int end;
	int sum;

};

void heapify(struct time *a, int i, int n)
{
	while (1){
		int left=2*i+1;
		int right=2*i+2;
		int j=i;
		if ((left<n) && a[left].sum<a[i].sum)
			i=left;
		if ((right<n) && a[right].sum<a[i].sum)
			i=right;
		if (i==j)
			break;
		struct time temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
}

void buildheap(struct time *a, int n)
{
	int i=(n/2)-1;
	while (i>=0){
		heapify(a, i, n);
		i--;
	}
	
}

int extr(struct time *a, int *count)
{
	int res;
	res=a[0].sum;
	(*count)=(*count)-1;
	int c=(*count);
	if (c>0){
		a[0]=a[c];
		heapify(a, 0, *count);
	}
	return res;
}

void ins(struct time *a, int start, int end, int *count)
{
	int i=(*count);
	(*count)=i+1;
	a[i].start=start;
	a[i].end=end;
	a[i].sum=start+end;
	while (i>0 && a[i].sum<a[(i-1)/2].sum){
		struct time temp;
		temp=a[(i-1)/2];
		a[(i-1)/2]=a[i];
		a[i]=temp;
		i=(i-1)/2;
	}
}

int main (int argc, char **argv)
{
	int n, i, j, m;
	scanf("%d", &n);
	scanf("%d", &m);
	if(n>m)
		n=m;
		
	int start, end;
	int last, max;
	int count=n;
	struct time *a=(struct time*)malloc(n*sizeof(struct time));
	for (i=0; i<n; i++){
		scanf("%d %d", &start, &end);
		a[i].start=start;
		a[i].end=end;
		a[i].sum=start+end;
	}
	
	buildheap(a,n);
	
	for (i=n; i<m; i++){
		scanf("%d %d", &start, &end);
		last=extr(a, &count);
		if (last>start)
			start=last;
		
		ins(a, start, end, &count);
	}
	
	max=a[0].sum;
	for (i=0; i<n; i++){
		if (a[i].sum>max)
			max=a[i].sum;
	}
	printf("%d\n", max);
	free(a);
	return 0;
}
