#include <stdio.h>

int main (int argc, char **argv)
{
	long long int n, x0, i, pol=0, der=0; 
	
	scanf("%lld %lld", &n, &x0);
	long long int a[n+1];
	for (i=0; i<n+1; i++)
		scanf("%lld", &a[i]);
	long long int c[n+1];
	for (i=0; i<n+1; i++){
		c[i]=(n-i)*a[i];
		//printf("%lld ", c[i]);
	}
	//printf("\n");
	
	for (i=0; i<n; i++){
		
		pol = a[i] * x0;
		//printf("%lld ", pol);
		pol += a[i+1];
		a[i+1] = pol;
		//printf("%lld ", pol);
		
	} 
	//printf("\n");
	
	printf("%lld ", pol);
	
	
	for (i=0; i<n-1; i++){
		der = c[i] * x0;
		der+= c[i+1];
		c[i+1] = der;
	} 
	
	printf("%lld\n", der);
	
	return 0;
}
