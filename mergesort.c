#include <stdio.h>
#include <stdlib.h>

//убрать массив внутрь, тогда в сравнение добавить


int compare(int *a, int i, int j)
{
	if (abs(a[i])<abs(a[j]))
		return -1;
	if (abs(a[i])==abs(a[j]))
		return 0;
	if (abs(a[i])>abs(a[j]))
		return 1;
}

void insert(int *a, int low, int high, 
	int (*compare)(int *a, int i, int j))
{
	int i=low+1;
	while (i<=high){
		int loc=i-1;
		while (loc>=low && compare(a, loc+1, loc)<0){
			int temp=a[loc+1];
			a[loc+1]=a[loc];
			a[loc]=temp;
			loc--;
		}
		i++;
	}	
}
	

void merge(int *a, int k, int l, int m,
	int (*compare)(int *a, int i, int j))
{
	int len=m-k+1;
	int temp[len];
	int i=k, j=l+1, h=0;
	int s;
	while (h<len){
		if (j<=m && (i==l+1 || compare(a, j, i)<0)){
			temp[h]=a[j];
			j++;
		}else{
			temp[h]=a[i];
			i++;
		}
		h++;
	}
	for (s=0; s<h; s++)
		a[k+s]=temp[s];
	
}

void mergesortrec(int *a, int low, int high,
	int (*compare)(int *a, int i, int j))
{
	if (high-low+1<5)
		insert(a, low, high, compare);
	else{
		if (low<high){
			int med=(low+high)/2;
			mergesortrec(a, low, med, compare);
			mergesortrec(a, med+1, high, compare);
			merge(a, low, med, high, compare);
		}
		
	}
}

void mergesort(int *a, int nel,
	int (*compare)(int *a, int i, int j))
{
	mergesortrec(a, 0, nel-1, compare);
}

int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n);
        int *a=calloc(n, sizeof(int));
        for (i=0; i<n; i++)
        	scanf("%d", &a[i]); 
  
	mergesort(a, n, compare); 
	for (i=0; i<n; i++)
		printf("%d ", a[i]); 
	printf("\n"); 
	free(a);
	return 0; 
}

