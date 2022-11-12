#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int cap;
    int top;
    int *numb;
};

int main (int argc, char **argv)
{
	int i, n;
	scanf("%d", &n);
	
	struct stack a;
	a.numb=calloc(n+1, sizeof(int));
	a.cap=n; //может быть ошибку можно имправить просто плюсодинув
	a.top=1;
	
	for (i=0; i<n; i++){
		char *op=calloc(6, sizeof(char));
		scanf("%s", op);
		if (op[0]=='C' && op[1]=='O'){
			int x;
			scanf("%d", &x);
			/*if (a.top==a.cap){
				a.cap++;
				a.numb=(int*)realloc(a.numb, a.cap*sizeof(int));	
			}*/
			a.numb[a.top]=x;
			a.top++;
		}
		if (op[0]=='A' && op[1]=='D'){
			a.top--;
			a.numb[a.top-1]=a.numb[a.top]+a.numb[a.top-1];
		}
		if (op[0]=='S' && op[1]=='U'){
			a.top--;
			a.numb[a.top-1]=a.numb[a.top]-a.numb[a.top-1];
		}
		if (op[0]=='M' && op[1]=='U'){
			a.top--;
			a.numb[a.top-1]=a.numb[a.top]*a.numb[a.top-1];
		}
		if (op[0]=='D' && op[1]=='I'){
			a.top--;
			a.numb[a.top-1]=a.numb[a.top]/a.numb[a.top-1];
		}
		if (op[0]=='M' && op[1]=='A'){
			a.top--;
			if (a.numb[a.top]<a.numb[a.top-1])
				a.numb[a.top-1]=a.numb[a.top-1];
			else 
				a.numb[a.top-1]=a.numb[a.top];
		}
		if (op[0]=='M' && op[1]=='I'){
			a.top--;
			if (a.numb[a.top]>a.numb[a.top-1])
				a.numb[a.top-1]=a.numb[a.top-1];
			else a.numb[a.top-1]=a.numb[a.top];
		}
		if (op[0]=='N' && op[1]=='E')
			a.numb[a.top-1]=(-1)*a.numb[a.top-1];
		if (op[0]=='D' && op[1]=='U'){
			/*if (a.top==a.cap){
				a.cap++;
				a.numb=(int*)realloc(a.numb, a.cap*sizeof(int));	
			}*/
			a.numb[a.top]=a.numb[a.top-1];
			a.top++;
		}
		if (op[0]=='S' && op[1]=='W'){
			int temp=a.numb[a.top-1];
			a.numb[a.top-1]=a.numb[a.top-2];
			a.numb[a.top-2]=temp;
		}
		free(op);
	}
	printf("%d\n", a.numb[a.top-1]);
	free(a.numb);
	return 0;
}
