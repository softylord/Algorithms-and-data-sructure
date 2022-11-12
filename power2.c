#include <stdio.h>
#include <math.h>


int main (int argc, char **argv)
{
	int n, i, j, count=0, sum, max;
	scanf("%d", &n);
	int a[n];
	
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	int pow[30];
	pow[0]=1;
	for (i=1; i<30; i++)
		pow[i]=pow[i-1]*2;
		
	max=pow[n];
	for (i=1; i<max; i++){
        	sum=0;
        	for (j=0; j<n; j++)
        		if (i&(1<<j)){
        			//printf("Numbers: %d %d %d\n", i, 1<<j, a[j]);
        			sum+=a[j];
			}
		if (sum>0)
			for (j=0; j<30; j++)
				if (sum==pow[j]){
					count++;
					//printf("Others: %d %d\n", sum, count);
				}
    	}
    	printf ("%d\n", count);
    	return 0;
}

