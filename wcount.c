#include <stdio.h>

int wcount(char *s)
{
	int res=0, i, flag=0;
	//printf("here\n");
	/*if (s[0]!=' ')
		res++;*/
	for (i=1; s[i]!='\0'; i++)
		if (s[i]==' ' && s[i-1]!=' ')
			res++;
	//printf("%s %d\n", s[i-1], i);
	if (s[i-1]!=' ')
		res+1;
	return res;
}


int main (int argc, char **argv)
{
	char str[10000];
	fgets(str, 10000, stdin);
	//puts(str);
	printf("%d\n", wcount(str));
	//free(str);
	return 0;
	
}

