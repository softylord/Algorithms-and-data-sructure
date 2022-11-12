#include <stdio.h>

int a[5]={ 1, 2, 3, 4, 10 };
int x=3;

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
	unsigned long left=0;
	unsigned long right=nel-1;
	unsigned long middle;
	unsigned long res=nel; 
	while (left<=right){
		middle=(left+right)/2;
		if (compare(middle)==-1)
			left=middle+1;
		if(compare(middle)==1)
			right=middle-1;
		if(compare(middle)==0)
			return middle;
	}
	return nel;
}


int comp (unsigned long i)
{
	if (x<a[i])
		return 1;
	else if (x==a[i])
		return 0;
	else return -1;
}


int main (int argc, char **argv)
{
	printf("%lu\n", binsearch(5, comp));
	return 0;
}
