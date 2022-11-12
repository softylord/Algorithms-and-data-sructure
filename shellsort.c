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

unsigned long maxfib(unsigned long d)
{
	unsigned long i=0, j=1, k=1, temp;
	if (d==1)
		return 0;
	while (k<d) {
		temp=i;
		i=j;
		j=j+temp;
		if ((i+j)>=d)
			return j;
		else 
			k=i+j;
	}
	return k;

}

void shellsort(unsigned long nel,
	int (*compare)(unsigned long i, unsigned long j),
	void (*swap)(unsigned long i, unsigned long j))
{
	unsigned long d=maxfib(nel), i, j;
	int loc;
	while (d>=1) {
		i=d;
		while (i<nel) {
			loc=i-d;
			while ((loc>=0)&&(compare(loc+d, loc)==-1)) {
				swap (loc+d, loc);
				loc=loc-d;
			}
			i++;
		}
		d=maxfib(d);
		i=d;
	}
}

int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n);
        a=malloc(sizeof(int)*n);
        for (i=0; i<n; i++)
        	scanf("%d", &a[i]); 
 
        shellsort(n, compare, swap); 
        for (i=0; i<n; i++)
        	printf("%d ", a[i]); 
        printf("\n"); 
        free(a);
        return 0; 
}

