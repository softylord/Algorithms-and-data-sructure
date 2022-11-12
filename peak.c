#include<stdio.h>

int a[8]={7, 8, 6, 5, 4, 3, 2, 1};

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
	unsigned long int i;
	int j;
	if (nel==1)
		return 0;
	else if (less (0, 1)==0)
		return 0;
	else if (less (nel-2, nel-1))
		return nel-1;
	else for (i=1; i<nel-1; i++)
		if ((less(i-1, i)==1)&&(less(i, i+1)==0))
			return i;
}

int less(unsigned long i, unsigned long j)
{
	if (a[i]<a[j])
		return 1;
	else return 0;
}

int main (int argc, char **argv)
{
	printf("%lu\n", peak(8, less));
	return 0;
}
