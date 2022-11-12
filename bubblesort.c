#include <stdio.h>
#include <stdlib.h>

int *a;

int compare(unsigned long i, unsigned long j)
{
	if (a[i]<a[j])
		return -1;
	if (a[i]==a[j])
		return 0;
	if (a[i]>a[j])
		return 1;
}

void swap(unsigned long i, unsigned long j) 
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void bubblesort(unsigned long nel, 
	int (*compare)(unsigned long i, unsigned long j),
	void (*swap)(unsigned long i, unsigned long j))
{
	unsigned long left=0, right=nel-1, i, j;
	if (nel>1)
		for (i=0; i<nel-1; i++){
			if (i%2==0){
				for (j=left; j<right; j++){
					if (compare(j, j+1)==1)
						swap(j, j+1);
				}
				//left+=1;
				right-=1;
			}else {
				for (j=right; j>left; j--){
					if (compare(j-1, j)==1)
						swap(j-1, j);
				}
				//right-=1;
				left+=1;
			}
		}
}

int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n);
        a=malloc(sizeof(int)*n);
        for (i = 0; i < n; i++)
        	scanf("%d", &a[i]); 
 
        bubblesort(n, compare, swap); 
        for (i = 0; i < n; i++)
        	printf("%d ", a[i]); 
        printf("\n"); 
        free(a);
        return 0; 
}

