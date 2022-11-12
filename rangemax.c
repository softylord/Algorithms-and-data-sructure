#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b)
{
	return (a>b)? a:b;
}

void upd(int j, int v, int a, int b, int *t, int x)
{
	if (a==b)
		t[x]=v;
	else{
		int m=(a+b)/2;
		if (j<=m)
			upd(j, v, a, m, t, 2*x+1);
		else
			upd(j, v, m+1, b, t, 2*x+2);
		t[x]=max(t[2*x+1], t[2*x+2]);
	}
}

void stupd(int j, int v, int *t, int n)
{
	upd(j, v, 0, n-1, t, 0);
}

void build(int *arr, int a, int b, int *t, int x)
{
	if (a==b)
		t[x]=arr[a];
	else{
		int m=(a+b)/2;
		build(arr, a, m, t, 2*x+1);
		build(arr, m+1, b, t, 2*x+2);
		t[x]=max(t[2*x+1], t[2*x+2]);
	}
}

void stbuild(int *a, int *t, int n)
{
	build(a, 0, n-1, t, 0);
}

int query(int *t, int l, int r, int a, int b, int x)
{
	int v;
	if (l==a && r==b)
		return t[x];
	else {
		int m=(a+b)/2;
		if (r<=m)
			return query(t, l, r, a, m, 2*x+1);
		else if (l>m)
			return query(t, l, r, m+1, b, 2*x+2);
		else
			return max(query(t, l, m, a, m, 2*x+1), query(t, m+1, r, m+1, b, 2*x+2));
	} 
} 

int stquery (int *t, int n, int l, int r)
{
	return query(t, l, r, 0, n-1, 0);
}

int main (int argc, char **argv)
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	/*for (i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	int *t=calloc(4*n, sizeof(int));
	stbuild(a, t, n);
	int m;
	//printf("m: ");
	scanf("%d", &m);
	char op[4];
	//printf("%d\n", m);
	for (i=0; i<m; i++){
		scanf("%s", op);
		if (op[0]=='M'){
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", stquery(t, n, l, r));
		}
		if (op[0]=='U'){
			int j, v;
			scanf("%d %d", &j, &v);
			stupd(j, v, t, n);
		}
	}
	free(t);
	return 0;
}
































