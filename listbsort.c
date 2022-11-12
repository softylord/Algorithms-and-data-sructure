#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int len=10000;

struct Elem
{
    struct Elem *next;
    char *word;
};

struct Elem *initempty()
{
	struct Elem *a=(struct Elem*)malloc(sizeof(struct Elem));
	a->next=NULL;
	a->word=NULL;
	return a;
}

int listlength(struct Elem *a)
{
	int length=0;
	struct Elem *helper=a;
	while (helper!=0){
		length++;
		helper=helper->next;
	}
	return length;
}

int compare(struct Elem *a, struct Elem *b)
{
	return (strlen(a->word)-strlen(b->word));
}

void swap(struct Elem *a, struct Elem *b)
{
	char *temp=a->word;
	a->word=b->word;
	b->word=temp;
}

struct Elem *bsort(struct Elem *list)
{
	struct Elem *a;
	int length=listlength(list->next)-1;
	while(length>0){
		int i=0, temp=length;
		length=0;
		a=list->next;
		while(i<temp){
			if (compare(a, a->next)>0){
				swap(a, a->next);
				length=i;
			}
			a=a->next;
			i++;
		}
	}
}

int main (int argc, char **argv)
{
	struct Elem *head=initempty();
	struct Elem *tail=head;
	struct Elem *cur;
	char *sent=malloc(len*sizeof(char));
	fgets(sent, len, stdin);
	char *wrd=strtok(sent, " ");
	while (wrd!=0){
		cur=initempty();
		cur->word=wrd;
		if (head->next==NULL)
			head->next=cur;
		else
			tail->next=cur;
		tail=cur;
		wrd=strtok(NULL, " ");
	}
	bsort(head);
	struct Elem *a=head->next;
	while (a!=NULL){
		printf("%s ", a->word);
		tail=a;
		a=a->next;
		free(tail);
	}
	printf("\n");
	free(sent);
	free(head);
	return 0;
}

















