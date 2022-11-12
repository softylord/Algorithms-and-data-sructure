#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc<2){
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	if (strlen(argv[3])+1>=atoi(argv[2])){
		printf("Error\n");
		return 0;
	}
	
	 int hgt=atoi(argv[1]);
	 int wdth=atoi(argv[2]);
	 int area=hgt*(wdth+1);
	 int i, j;
	 int mddl=((hgt-1)/2)*(wdth+1)+((wdth-strlen(argv[3]))/2);
	 //printf("%d\n", mddl);
	 //printf("\n");
	 char *frm=calloc(area+1, sizeof(char));
	 memset(frm, ' ', area);
	 memset(frm, '*', wdth);
	 memset(&frm[area-wdth-1], '*', wdth);
	 for (i=0; i<area; i+=wdth+1){
	 	frm[i]='*';
	 	frm[i+wdth-1]='*';
	 	frm[i+wdth]='\n';
	 }
	 strncpy(&frm[mddl], argv[3], strlen(argv[3]));
	 printf("%s", frm);
	 free(frm);
	 return 0;
	
}
