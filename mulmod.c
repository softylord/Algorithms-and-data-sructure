#include <stdio.h>


int main (int argc, char **argv)
{
	long long int i, a, b, m;
	unsigned long long res=0;
	scanf("%llu %llu %llu", &a, &b, &m);
	
	long long int c[64];
	
	//if (b >= a) {
		for (i=63; i>=0; i--){
			c[i]=b%2;
			b=b/2;
		}
		//printf("%llu\n", mulmod(a, c, m, 0));
		
	/*} else {
		for (i=63; i>=0; i--){
			c[i]=a%2;
			a=a/2;
		}
		printf("%llu\n", mulmod(b, c, m, 0));
	}*/
	
	for (i=0; i<64; i++)
		res=((res*2%m)+(c[i]*a)%m)%m;
	printf("%llu\n", res);
	return 0;
}
