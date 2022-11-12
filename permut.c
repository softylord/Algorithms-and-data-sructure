#include <stdio.h>

int main (int argc, char **argv)
{
	long long i, j, a[8], b[8], c1, c2, c=0 ;
	//printf("Print elements of the first:\n");
	for (i=0; i<8; i++)
		scanf("%lld", &a[i]);
	//printf("Print elements of the second:\n");
	for (i=0; i<8; i++)
		scanf("%lld", &b[i]);
	
	//printf("\n");
	for (i=0, c1=0, c2=0; i<8; i++){
		for (j=0; j<8; j++)
			if (a[i]==a[j]) c1+=1;
		for (j=0; j<8; j++) 
			if (a[i]==b[j]) c2+=1;
		if (c1==c2)  c+=1;
	}
	if (c==8) printf("yes\n");
	else printf("no\n");	
	return 0;
}
