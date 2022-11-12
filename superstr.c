#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int arr[10];
int helper[10];
int cross[10][10];
int strsz;
// сравниваем поэлементно две строки, ищем длину совпадения конца 1 строки с началом 2 строки
// так все строки между собой
// НЕТОЧНО! пробуем посчитать сумму длин строк и вычесть из них длины совпадений

int min(int i, int len, int count, int n)
{
	int flag=1, j, k;
	//printf("here\n");
	if (count==n-1){
		//printf("%d %d\n", count, n); 
		if (strsz>len)
			strsz=len;
	}
	else{
		//printf("here\n");
		for (j=0; j<n; j++){
			helper[count]=i;
			//printf("%d\n", strsz);
			for (k=0; k<=count; k++){
				if (helper[k]==j){
					flag=0;
					break;
				}
			}
			if (flag)
				min(j, len+arr[j]-cross[i][j], count+1, n);
			flag=1;
		}
	}	
}

int main (int argc, char **argv)
{
	int n, i, j, k;
	scanf("%d", &n);
	char *a[n];
	for (i=0; i<n; i++){
		a[i]=malloc(sizeof(char)*10000);
		scanf("%s", a[i]);
		arr[i]=strlen(a[i]);
	}
	/*for (i=0; i<n; i++)
		printf("%d\n", arr[i]);*/
		
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			int l=1, flag=1, x, y;
			while (flag && l<arr[i]){
				y=0;
				x=l;
				while (a[i][x]==a[j][y] && y<arr[j] && x<arr[i]){
					x++;
					y++;
				}
				if (x==arr[i]){
					//printf("here\n");
					cross[i][j]=arr[i]-l;
					flag=0;
				}
				l++;
			}
		}
	}
	/*for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			printf("%d ", cross[i][j]);
	printf("\n");*/
	//int strsz;
	if (n==1)
		strsz=arr[0];
	else{
		strsz=10000;
		for (i=0; i<n; i++)
			min(i, arr[i], 0, n);
	}
		
	printf("%d\n", strsz);
	for (i=0; i<n; i++)
		free(a[i]);
	return 0;
	
}
