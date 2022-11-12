#include<stdio.h>

int cmp(void *a, void *b)
{
	return ( *(int*)a - *(int*)b);
}

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
	int i, s=0;
	void *max=base;
	char *x =(char *)base;
	for (i=1; i<nel; i++){
		x+=width;
		if (compare(x, max)>=0){
			s=i;
			max=x;
		}
	}
	return s;
}

int main (int argc, char **argv)
{
	int a[6]={ 40, -5, 13, 22, 8, 0 };
	printf("%d\n", maxarray(a, 6, sizeof(int), cmp));
	return 0;
}
