#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ptrie{
	struct ptrie *arcs[26];
	long int keyw;
	long int keys;
} *root;

struct ptrie *initptrie()
{
	struct ptrie *ptr=malloc(sizeof(struct ptrie));
	ptr->keyw=ptr->keys=0;
	int i;
	for(i=0; i<26; i++)
		ptr->arcs[i]=NULL;
	return ptr;
}

long int find(char k)
{
	char key[26]="abcdefghijklmnopqrstuvwxyz";
	int i=0;
	for (i=0; i<26; i++)
		if (k==key[i])
			return i;
}

void insert(struct ptrie *a, char *k)
{
	struct ptrie *ptr=a;
	long int i, len=strlen(k), findk;
	for (i=0; i<len; i++){
		findk=find(k[i]);
		if (ptr->arcs[findk]==NULL)
			ptr->arcs[findk]=initptrie();
		ptr=ptr->arcs[findk];
		ptr->keys++;
	}
	if (ptr->keyw==0)
		ptr->keyw++;
	else{
		ptr=a; 
		for(i=0; i<len; i++){
			findk=find(k[i]);
			ptr=ptr->arcs[findk];
			ptr->keys--;
		}
	}
}

void prefix(struct ptrie *a, char *k)
{
	struct ptrie *ptr=a;
	long int i, len=strlen(k), findk;
	for (i=0; i<len; i++){
		findk=find(k[i]);
		if (ptr->arcs[findk]==NULL){
			printf("%d\n", 0);
			return;
		}
		ptr=ptr->arcs[findk];
	}
	printf("%ld\n", ptr->keys);
}

void delete(struct ptrie *a, char *k)
{
	struct ptrie *ptr=a;
	long int i, len=strlen(k), findk;
	for (i=0; i<len; i++){
		findk=find(k[i]);
		ptr=ptr->arcs[findk];
		ptr->keys--;
	}
	ptr->keyw--;
}

int main (int argc, char **argv)
{
	root=initptrie();
	long int i, n, m;
	scanf("%ld", &n);
	char a[10];
	char *k=(char*)malloc(sizeof(char)*100000);
	for(i=0; i<n; i++){
		scanf("%s %s", a, k);
		if (a[0]=='I'){
			insert(root, k);
			continue;
		}
		if (a[0]=='D'){
			delete(root, k);
			continue;
		}
		if (a[0]=='P'){
			prefix(root, k);
			continue;
		}
	}
	free(k);
	return 0;
}














