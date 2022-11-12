#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
	a=abs(a);
	b=abs(b);
	if (a==0)
		return b;
	else if (b==0)
		return a;
	else if (a==b)
		return a;
	else if (a==1 || b==1)
		return 1;
	else if (a>b)
		return gcd(a%b, b);
	else
		return gcd(a, b%a);
}

void stbuild(long int *a, int n, int **st)
{
	int m=log2(n)+1;
	int i=0, j=1;
	while (i<n){
		st[i][0]=a[i];
		i++;
	}
	while (j<m){
		i=0;
		while (i<=n-(1<<j)){
			st[i][j]=gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
			i++;
		}
		j++;
	}
}

void stquery (int **st, int left, int right)
{
	int j=log2(right-left+1);
	printf("%d\n", gcd(st[left][j], st[right-(1<<j)+1][j]));
}

int main (int argc, char **argv)
{
	int n, i, m, j;
	scanf("%d", &n);
	long int a[n];
	for (i=0; i<n; i++)
		scanf("%ld", &a[i]);
		
	int b=log2(n)+1;
	int **st=malloc(n*sizeof(int*));
	for (i=0; i<n ; i++)
		st[i]=malloc(b*sizeof(int));
	stbuild(a, n, st);
	
	scanf("%d", &m);
	for (i=0; i<m; i++){
		int left, right;
		scanf("%d %d", &left, &right);
		stquery(st, left, right);
	}
	
	for (i=0; i<n; i++)
		free(st[i]);
	free(st);
	return 0;
}
