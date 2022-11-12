#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//СКОРЕЕ ВСЕГО ПРОБЛЕМА СО СВАПАМ

int compare(const void *a, const void *b)
{
	size_t i=0, lena=0, lenb=0;
	while (*(char *)(((char*)a)+i)!='\0'){
		if (*(char *)(((char*)a)+i)=='a')
			lena+=1;
		i++;
	}
	i=0;
	while (*(char *)(((char*)b)+i)!='\0'){
		if (*(char *)(((char*)b)+i)=='a')
			lenb+=1;
		i++;
	}
	if (lena<lenb)
		return -1;
	else if (lena==lenb)
		return 0;
	else return 1;
}

void swap(void *a, void *b, size_t width)
{
	size_t i;
	void *temp=malloc(width);
	for(i=0; i<width; i++){
		*(char *)(((char*)temp)+i)=*(char *)(((char*)a)+i);
		*(char *)(((char*)a)+i)=*(char *)(((char*)b)+i);
		*(char *)(((char*)b)+i)=*(char *)(((char*)temp)+i);
	}
	free(temp);
}

void heapify(void *base, size_t i, size_t n, size_t width,
	int (*compare)(const void *a, const void *b))
{
	while (1){
		size_t left=2*i+1*width;
		size_t right=2*i+2*width;
		size_t j=i;
		if ((left<n*width)&&compare(((char*)base)+i, ((char*)base)+left)<0)
			i=left;
		if ((right<n*width)&&compare(((char*)base)+i, ((char*)base)+right)<0)
			i=right;
		if (i==j)
			break;
		swap(((char*)base)+i, ((char*)base)+j, width);
	}
	
}

void buildheap(void *base, size_t n, size_t width,
	int (*compare)(const void *a, const void *b))
{
	size_t i=(n/2)*width;
	while (i>0){
		heapify(base, i-width, n, width, compare);
		i-=width;
		//printf("%ld\n", i);
	}
	
}

void hsort(void *base, size_t nel, size_t width,
	int (*compare)(const void *a, const void *b))
{
	size_t i;
	buildheap(base, nel, width, compare);
	for (i=1; i<nel; i++){
		swap(base, ((char*)base)+(nel-i)*width, width);
		heapify(base, 0, nel-i, width, compare);
	}
	/*size_t i;
	for (i=nel/2; i>0; i--)
		heapify(base, i-1, nel, width, compare);
	for (i=nel-1; i>0; i--){
		swap(base, base+i, width);
		heapify(base, 0, i, width, compare);
	}*/
}

int main(int argc, char **argv) 
{ 
       size_t nel, i;
       scanf("%lu", &nel);
       char base[nel][256];
       for (i=0; i<nel; i++){
		scanf("%s", base[i]);
	}
	
	hsort(base, nel, sizeof(char)*256, compare);

	for (i=0; i<nel; i++)
		puts(base[i]);	

        return 0; 
}

