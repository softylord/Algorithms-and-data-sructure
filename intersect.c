#include <stdio.h>
#include <math.h>
int main (int argc, char **argv)
{
	int n;
	
	long long a, b, d;
	//printf("Number of A elements: ");
	scanf("%d", &n);
	
	int i, c[n];
	for (i=0, a=0; i<n; i++)
		scanf("%d", &c[i]);
	
	for (i=0, a=0; i<n; i++)
		a=a+pow(2, c[i]);

	//printf("Number of B elements: ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++)
		scanf("%d", &c[i]);

	for (i=0, b=0; i<n; i++)
		b=b+pow(2, c[i]);
	//printf("\n");
	d=a&b;
	
	for (i=0; i<32; i++){
		if (d%2) printf("%d\n", i);
		d=d/2;
	}
	return 0;
}
