#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int *numb;
	int cap;
	int count;
	int head;
	int tail;
};

int main (int argc, char **argv)
{
	int i, n, j, tail;
	scanf("%d", &n);
	
	struct queue a;
	a.numb=calloc(4, sizeof(int));
	a.cap=4;
	a.count=0;
	a.head=0;
	a.tail=0;
	
	for (i=0; i<n; i++){
		char *op=calloc(6, sizeof(char));
		scanf("%s", op);
		if (op[0]=='E' && op[1]=='N'){
			int x;
			scanf("%d", &x);
			if (a.count==a.cap){
				int cap=a.cap;
				a.cap*=2;
				a.numb=(int*)realloc(a.numb, a.cap*sizeof(int));
				for (j=a.head; j<a.cap/2; j++){
					a.numb[j+a.cap/2]=a.numb[j];
					a.numb[j]= 0; 
				}
				/*for (j=0; j<a.cap; j++)
					printf("%d ", a.numb[j]);
				printf("\n");*/
				a.head+=a.cap/2;
				//printf("%d\n", a.head);
			}
			a.numb[a.tail]=x;
			//printf("%d\n", a.numb[a.tail]);
			a.tail++;
			if (a.tail==a.cap)
				a.tail=0;
			a.count++;
			/*for (j=0; j<a.cap; j++)
				printf("%d ", a.numb[j]);
			printf("\n");*/
		}
		if (op[0]=='D' && op[1]=='E'){
			printf("%d\n", a.numb[a.head]);
			a.head++;
			if (a.head==a.cap)
				a.head=0;
			a.count--;
		}
		if (op[0]=='E' && op[1]=='M'){
			if (a.count)
				printf("false\n");
			else
				printf("true\n");
		}
		free(op);
	}
	free(a.numb);
	return 0;
}
