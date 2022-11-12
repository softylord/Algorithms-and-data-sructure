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

int maxdiv(int a, int b) //алгоритм Евклида (важная в жизни штука, надо выучить)
{
	int c=a%b, d=b%a;
	if (c==0)
		return d;
	if (d==0)
		return c;
	if (c>d)
		return maxdiv(a, d);
	if (c<d)
		return maxdiv(b, c);
}

void findprefix(char *s, int *pi, int lens)
{
	int i, j;
	for (i=1; i<lens; i++)
		if (pi[i]!=0){
			int k=maxdiv(i+1, pi[i]); //наибольший делитель это шаг 
			int flag=1;
			for (j=0; j<i-k; j++)
				if (s[j]!=s[j+k])
					flag=0;
			if (flag)
				printf("%d %d\n", i+1, (i+1)/k);		
		}
		
}

int main(int argc, char **argv) 
{ 
	int lens=strlen(argv[1]);
	char s[lens];
	int pi[lens];
	int i;
	strncpy(s, argv[1], lens);
	prefix(s, pi, lens);
	/*for (i=0; i<lens; i++)
		printf("%d ", i);
	printf("\n");
	for (i=0; i<lens; i++)
		printf("%d ", pi[i]);
	printf("\n");*/
	findprefix(s, pi, lens);
	//printf("%s\n", s);	
	return 0;
}

