#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *concat(char **s, int n)
{
	int i, j;
	int strsz=0;
	
	for (i=0; i<n; i++)
		strsz+=strlen(s[i]);
	
	char *res=malloc(sizeof(char)*strsz);
	int k=0;
	for (i=0; i<n; i++){
		j=0;
		while (s[i][j]!='\0'){
			res[k]=s[i][j];
			j++;
			k++;
		}
	}
	res[k]='\0';
	return res;
	free(res);
	
}

int main (int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	char *a[n];
	for (i=0; i<n; i++){
		a[i]=malloc(sizeof(char));
		scanf("%s", a[i]);
	}
	char *res = concat(a, n);
	puts(res);
	for (i=0; i<n; i++)
		free(a[i]);
	return 0;
}

