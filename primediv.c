#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	long long int i, j=0, k=0, s, m, l;	
	long long int  x;
	//printf("Print x: ");
	scanf("%lld", &x);
	x=abs(x);
	
	
	long long int n=x/8;
	//n=abs(n);
	long long int *a;
    	a=calloc(n+1, sizeof(long long int)); 
	long long int res=1;
	
	
	for (i=0; i<n; i++)
		a[i] = 0;
		
	for (i=2; i<=x; i++){
		j=i/8;
		k=i%8;
		//printf("%d ", i);
		if (((a[j]>>k)&1)==0){
			//printf("%lld %x \n", i, a[j]);
            		if(x%i==0)
            			res=i;
            		for (s=i*2; s<=x; s=s+i){
            			m=s/8;
            			l=s%8;
            			//printf("rrrrr %lld %lld \n", m, l);
            			a[m]=a[m]|(1<<l);
            		}	
		}
	}
	printf("%lld\n", res);
	free(a);
	return 0;
}
