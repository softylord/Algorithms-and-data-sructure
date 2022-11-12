#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delta1(char *s, int *q, int len)
{
	int a=0, j, size=256;
	while (a<size){
		q[a]=len;
		a++;
	}
	j=0;
	while (j<len){
		q[s[j]]=len-j-1;
		j++;
	}
}

void suffix(char *s, int *q, int len)
{
	int t=len-1, i;
	q[len-1]=t;
	i=len-2;
	while(i>=0){
		while (t<(len-1) && s[t]!=s[i])
			t=q[t+1];
		if (s[t]==s[i])
			t--;
		q[i]=t;
		i--;
	}
}

void delta2(char *s, int *q, int len)
{
	int suff[len];
	suffix(s, suff, len);
	int i=0;
	int t=suff[0];
	while (i<len){
		while(t<i)
			t=suff[t+1];
		q[i]=-i+t+len;
		i++;
	}
	i=0;
	while (i<len-1){
		t=i;
		while (t<len-1){
			t=suff[t+1];
			if (s[i]!=s[t])
				q[t]=-(i+1)+len;
		}
		i++;
	}	
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

void bmsubst(char *s, char *t, int lens, int lent)
{
	int k, i, q1[256], q2[lens];
	delta1(s, q1, lens);
	delta2(s, q2, lens);
	k=lens-1;
	while (k<lent){
		i=lens-1;
		while(t[k]==s[i]){
			if (i==0){
				printf("%d ", k);
				break;
			}
			i--;
			k--;
		}
		k+=max(q1[t[k]], q2[i]);
	}
	printf("\n");
}

int main(int argc, char **argv) 
{ 
	int lens=strlen(argv[1]);
	int lent=strlen(argv[2]);
	char s[lens];
	char t[lent];
	strncpy(s, argv[1], lens);
	strncpy(t, argv[2], lent);
	bmsubst(s, t, lens, lent);
	return 0;
}

