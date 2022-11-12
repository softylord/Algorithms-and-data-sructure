#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char *str)
{
	int i, j;
	int a[26]={0};
	int len=strlen(str);
	for (i=0; i<len; i++){
		a[str[i]-'a']++;
		//printf("1\n");
	}
	//printf("here2\n");
	for (i=0; i<26; i++)
		while (a[i]){
			*str=(char)i+97;
			str++;
			a[i]--;
		}
}

int main(int argc, char **argv) 
{ 
	char str[1000000];
	//printf("here1\n");
	scanf("%s", str);
	//printf("here1\n");
	dsort(str);
	printf("%s\n", str);
	return 0;
}

