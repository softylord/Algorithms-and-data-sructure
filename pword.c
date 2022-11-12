#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int *pi, int lens)
{
	int t=0, i=1;
	pi[0]=0;
	while (i<lens){
		while ((t>0) && s[t]!=s[i])
			t=pi[t-1];
		if (s[t]==s[i])
			t++;
		pi[i]=t;
		i++;
	}
}

int kmpsubst(char *s, char *t, int lens, int lent, int *pi)
{
	int q=0, k=0;
	while (k<lent){
		while ((q>0) && (s[q]!=t[k]))
			q=pi[q-1];
		if (s[q]==t[k])
			q++;
		if (q==0)
			return 0;
		k++;
	}
	return 1;
}

int main(int argc, char **argv) 
{ 
	int lens=strlen(argv[1]);
	int lent=strlen(argv[2]);
	char s[lens];
	char t[lent];
	//strncpy(s, argv[1], lens);
	//strncpy(t, argv[2], lent);
	int pi[lens];
	prefix(argv[1], pi, lens);
	if (kmpsubst(argv[1], argv[2], lens, lent, pi)==1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}

