#include <stdio.h>

int main (int argc, char **argv)
{
	/*НАИБОЛЬШИЙ в СТРОКЕ
	  НАИМЕНЬШИЙ в СЛБЦЕ*/
	
	int i, j;
	int m, n; // n - строчка, m - колонка
	//printf("Print n, m: ");
	scanf("%d %d", &n, &m);
	
	char check=1;
	
	int a[n][m], max_crds[n], min_crds[m], max_nmbr[n], min_nmbr[m];
	
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	
	/*printf("\n");
	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	printf("\n");*/
	
	for (i=0; i<n; i++)
		for (j=0; j<m; j++){
			//printf("%d\n", a[i][j]);
			int tmpr=a[i][j];
				
				if (i==0){
					min_nmbr[j]=tmpr;
					min_crds[j]=10*i+j;
					//printf("Mins: %d %d- %d, %d\n", i, j, min_nmbr[j], min_crds[j]);
				}	
				if (j==0){
					max_nmbr[i]=tmpr;
					max_crds[i]=10*i+j;
					//printf("Maxs: %d %d- %d, %d\n", i, j, max_nmbr[i], max_crds[i]);
				}
				if ((tmpr>max_nmbr[i])&&(j!=0)){
					max_nmbr[i]=tmpr;
					max_crds[i]=10*i+j;
					//printf("Maxs1: %d %d- %d, %d\n", i, j, max_nmbr[i], max_crds[i]);
				}
				if ((tmpr<min_nmbr[j])&&(i!=0)){
					min_nmbr[j]=tmpr;
					min_crds[j]=10*i+j;
					//printf("Mins1: %d %d- %d, %d\n", i, j, min_nmbr[j], min_crds[j]);
				}
		}
			
	/*printf("\n");
	
	for (i=0; i<n; i++)
		printf("%d (%d) ", max_nmbr[i], max_crds[i]);
	printf("\n");
	
	for (i=0; i<m; i++)
		printf("%d (%d) ", min_nmbr[i], min_crds[i]);
	printf("\n");
	printf("\n");*/
	for (i=0; i<n; i++)
		for(j=0; j<m; j++){
			//printf("%d, %d\n", max_crds[i], min_crds[j]);
			if (max_crds[i]==min_crds[j]){
				printf("%d %d\n", max_crds[i]/10, max_crds[i]%10);
				check=0;
				break;
			}
		}
	//printf("\n");
	if (check==1)
		printf("none\n");
	return 0;
}



























