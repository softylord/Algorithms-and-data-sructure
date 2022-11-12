#include <stdio.h>
#include <stdlib.h>


int compare(int *a, int i, int j)
{
	if (a[i]<a[j])
		return -1;
	if (a[i]==a[j])
		return 0;
	if (a[i]>a[j])
		return 1;
}

void swap(int *a, int i, int j) 
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}


int partition(int *a, int low, int high,
	int (*compare)(int *a, int i, int j),
	void (*swap)(int *a, int i, int j))
{
	int i=low;
	int j=low;
	while (j<high){
		if (compare(a, j, high)<0){
			swap(a, i, j);
			i++;
		}
		j++;
	}
	swap(a, i, high);
	return i;
}

void selectsort(int *a, int low, int high,
	int (*compare)(int *a, int i, int j),
	void (*swap)(int *a, int i, int j))
{
	int j=high;
	while (j>low){
		int k=j;
		int i=j-1;
		while (i>=0){
			if (compare(a, k, i)<0)
				k=i;
			i--;
		}
		swap(a, j, k);
		j--;
	}
}

void quicksortrec(int *a, int low, int high, int m,
	int (*compare)(int *a, int i, int j),
	void (*swap)(int *a, int i, int j))
{
	int q;
	while (low<high){
		if (high-low+1<m){
			selectsort(a, low, high, compare, swap);
			break;
		}
		q=partition(a, low, high, compare, swap);
		if ((q-low)<(high-q)){
			quicksortrec(a, low, q-1, m, compare, swap);
			low=q+1;
		}
		else{
			quicksortrec(a, q+1, high, m, compare, swap);
			high=q-1;
		}
	}	
}

void quicksort(int *a, int n, int m,
	int (*compare)(int *a, int i, int j),
	void (*swap)(int *a, int i, int j))
{
	quicksortrec(a, 0, n-1, m, compare, swap);
}

int main(int argc, char **argv) 
{ 
        int i, n, m; 
        scanf("%d %d", &n, &m);
         int *a=calloc(n, sizeof(int));
        for (i=0; i<n; i++)
        	scanf("%d", &a[i]); 
  
	quicksort(a, n, m, compare, swap); 
	for (i=0; i<n; i++)
		printf("%d ", a[i]); 
	printf("\n"); 
	free(a);
	return 0; 
}

