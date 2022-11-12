#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int *pi, int lens)
{
	int j;
	for (j=0; j<lens; j++)
		pi[j]=0;
	int t=0;
	int i=1;
	while (i<lens){
		while (t>0 && s[t]!=s[i])
			t=pi[t-1];
		if (s[t]==s[i])
			t++;
		pi[i]=t;
		i++;
	}
}

void kmpsubst(char *s, char *t, int lens, int lent)
{
	int pi[lens];
	prefix(s, pi, lens);
	int q=0, k=0;
	while (k<lent){
		while (q>0 && (s[q]!=t[k]))
			q=pi[q-1];
		if (s[q]==t[k])
			q++;
		if (q==lens){
			k=k-lens+1;
			printf("%d\n", k);
			q=0;
		}
		k++;
	}
}

int main(int argc, char **argv) 
{ 
	int lens=strlen(argv[1]);
	int lent=strlen(argv[2]);
	char s[lens];
	char t[lent];
	int i;
	strncpy(s, argv[1], lens);
	strncpy(t, argv[2], lent);
	kmpsubst(s, t, lens, lent);
	return 0;
}

