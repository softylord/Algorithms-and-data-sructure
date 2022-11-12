#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};


void distsort(int m, int n, union Int32 *a, int index)
{
	int count[m], k, s;
	union Int32 b[n];
	for (s=0; s<m; s++)
		count[s]=0;
	int j=0;
	while (j<n){
		if (index==3)
			k=(a[j].bytes[index]+128)%256; //проверка на отрицательность
		else
			k=a[j].bytes[index];
		count[k]++;
		//printf("%d %d %d %d\n", a[j].x, j, k, count[k]);
		j++;
	}
	//printf("here1\n");
	int i=1;
	while (i<m){
		count[i]=count[i]+count[i-1];
		i++;
	}
	for (i=0; i<n; i++)
		//printf("%d ", count[i]);
	//printf("\n");
	//printf("here2\n");
	j=n-1;
	i=0;
	while (j>=0){
		//printf("%d ", j);
		if (index==3)
			k=(a[j].bytes[index]+128)%256;
		else
			k=a[j].bytes[index];
		//printf("%d ", k);
		//printf("%d ", count[k]);
		i=count[k]-1;
		count[k]=i;
		//printf("%d\n", count[k]);
		b[i]=a[j];
		//printf("here2.1\n");
		j--;
	}
	//printf("here3\n");
	for (s=0; s<n; s++)
		a[s]=b[s];
}

void radixsort(int q, int m, int n, union Int32 *a)
{
	int i=0;
	while (i<q){
		distsort(m, n, a, i);
		i++;
	}
}

int main(int argc, char **argv) 
{ 
	int n, i;
	scanf("%d", &n);
	union Int32 a[n];
	for (i=0; i<n; i++)
		scanf("%d", &a[i].x);
	//printf("%d\n", a[2].bytes[3]);
	radixsort(4, 256, n, a);
	
	for (i=0; i<n; i++)
		printf("%d ", a[i].x);
	printf("\n");
			
	return 0;
}

