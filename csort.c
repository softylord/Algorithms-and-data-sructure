#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void csort(char *src, char *dest)
{
	int len, n=1, i, k=0;
	len=strlen(src);	
	for(i=0; i<len; i++) {
		if (src[i]==' ' && src[i+1]!=' ')
			n++;
		if (src[i]!=' ')
			k++;
	}
	if (src[0]==' ')
		n--;
	if (src[len-1]==' ')
		n--; 
	int key[n], j=0, h=0;
	for(i=0; i<len; i++) {
		if (src[i]!=' ') 
			j++;
		if (src[i]!=' ' && src[i+1]==' ') {
			key[h]=j;
			h++;
			j=0;
		}
	}
	key[h++]=j;
	int count[n];
	for (i=0; i<n; i++)
		count[i]=0;
	j=0;
	while (j<n-1) {
		i=j+1;
		while (i<n) {
			if (key[i]<key[j])
				count[j]+=key[i]+1;
			else
				count[i]+=key[j]+1;
			i++;
		}
		j++;
	}
	for(i=0; i<n+k; i++)
		dest[i]=' ';
		
	h=0;
	for(i=0; i<=len; i++) {
		if (src[i]!=' ') {
			for (j=0; j<key[h]; j++)
				dest[count[h]+j]=src[i+j];
			i+=key[h];
			h++;
		}
	}
	dest[n+k-1]='\0';
}
int main(int argc, char **argv) 
{
	int len=10000;
	char *src, *dest, i;
	src=calloc(len, sizeof(char));
	dest=calloc(len, sizeof(char));
	fgets(src, len, stdin);
	csort(src, dest);
	puts(dest);
	free(src);
	free(dest);
	return 0;
}
