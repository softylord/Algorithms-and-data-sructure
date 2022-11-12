#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n)
{
	char *res=malloc(sizeof(char)*n+1);
	if (n==1)
		return strcpy(res, "a");
	else if (n==2)
		return strcpy(res, "b");
	else{
		strcpy(res, fibstr(n-2));
		strcat(res, fibstr(n-1));
		return res;
	}		
	
}



int main (int argc, char **argv)
{
	int n, i;
	char *res;
	scanf("%d", &n);
	//for (i=1; i<=n; i++){
		//printf("%d: ", i);
		res=fibstr(n);
		//puts(res);
		//free(res);
	//}
	puts(res);
	free(res);
	return 0;
}
