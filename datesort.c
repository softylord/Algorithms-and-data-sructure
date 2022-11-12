#include <stdio.h>
#include <stdlib.h>

//надо как то сделать, чтоб с нулями в начале выводилося...

struct Date {
	int Day, Month, Year;
};

void setstruct(struct Date *D, struct Date *S, int m)
{
	int i;
	for (i=0; i<m; i++){
		D[i].Year=S[i].Year;
		D[i].Month=S[i].Month;
		D[i].Day=S[i].Day;
	}
}

int key(int m, int l, int n, struct Date *S)
{
	int elem, i, res, k=1;
	if (l==1)
		elem=S[n].Year;
	if (l==2)
		elem=S[n].Month;
	if(l==3)
		elem=S[n].Day;
	for (i=0; i<m; i++)
		k*=10;
	res=(elem/k)%10;
	return res;
}

void distsort(int (*key)(int m, int l, int n, struct Date *S), 
	int m, int n, int b, struct Date *S, int l)
{
	struct Date D[m];
	int count[n];
	for (int j=0; j<n; j++)
		count[j]=0;
	int j=0;
	while (j<m){
		int k=key(b, l, j, S);
		count[k]++;
		j++;
	}
	int i=1;
	while (i<n){
		count[i]=count[i]+count[i-1];
		i++;
	}
	j=m-1;
	while (j>=0){
		int k=key(b, l, j, S);
		i=count[k]-1;
		count[k]=i;
		D[i].Year=S[j].Year;
		D[i].Month=S[j].Month;
		D[i].Day=S[j].Day;
		j--;
	}
	setstruct(S, D, m);
}

void radixsort(int (*key)(int m, int l, int n, struct Date *S),
	int q, int m, int n, struct Date *S, int l)
{
	struct Date D[m];
	setstruct(D, S, m);
	int i=0;
	while (i<q){
		distsort(key, m, n, i, D, l);
		setstruct(S, D, m);
		i++;
		}
}

int main(int argc, char **argv) 
{ 
	int m, i;
	scanf("%d", &m);
	//printf("here1\n");
	struct Date dates[m];
	//printf("here2\n");
	for (i=0; i<m; i++)
		scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day); 
	//printf("here\n");
	radixsort(key, 2, m, 10, dates, 3);
	radixsort(key, 2, m, 10, dates, 2);
	radixsort(key, 4, m, 10, dates, 1);
	
	for (i=0; i<m; i++)
		printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day); 
			
	return 0;
}

