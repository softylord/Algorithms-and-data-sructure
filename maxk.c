#include <stdio.h>

int main (int argc, char **argv)
{
	int n, k, i;
	long long sum=0, summax=0;
	//printf("Print n: ");
	scanf("%d", &n);
	long long a[n];
	for (i=0; i<n; i++)
		scanf("%lld", &a[i]);
	//printf("Print k: ");
	scanf("%d", &k);
	for (i=0; i<k; i++)
		sum+=a[i];
	summax=sum;
	for (i=k; i<n; i++){
		sum=sum-a[i-k];
		sum=sum+a[i];
		if (sum>summax) summax=sum;
	}
	printf("%lld\n", summax);
	
	return 0;
}
