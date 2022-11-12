#include<stdio.h>

void revarray (void *base, size_t nel, size_t width)
{
	char *x =(char *)base;
	int i,j;
	for(i=0; i<nel/2; ++i){
		char *left=x+i*width;
		char *right=x+(nel-1-i)*width;
		for(j=0; j<width; ++j) {
			char a=left[j];
			left[j]=right[j];
			right[j]=a;
		}
	}
}

int main (int argc, char **argv)
{
	int a[]={ 1, 2, 3, 4, 5 };
	revarray((int*)a, 5, sizeof(int));
	for (int i=0; i<5; i++)
		printf("%d\n", a[i]);
	return 0;
}
