#include <stdio.h>

int main (int argc, char **argv)
{
	long long int n;
	long long int x, f[91], i, p;
	
	scanf("%lld", &x);
	
	for (i=0; i<91; i++){
		if (i==0) f[i]=1;
		else if (i==1) f[i]=2;
		else{
			f[i]=f[i-2]+f[i-1];
			n=i;
		}
	}
	
	if (x==0) printf("%d", 0);
	else{
		for (i=0; i<91; i++){
			if (x<f[i]){
				p=i-1;
				break;
			} else if (x==f[i]){
				p=i;
				break;
			} else p=90;
		}
		for (i=p; i>=0; i--){
			if (x-f[i]>=0){
				x=x-f[i];
				printf("%d", 1);
			}else printf("%d", 0);
		} printf("\n");
	}
	
	
				
	return 0;
}
