#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nextInt;
    char nextLine[10];
    FILE *fp = fopen("A:\TEST1.TXT", "r");

    if(fp==NULL){
	printf("Error opening file");
	return -1;
    }

    while(!feof(fp)){
	fgets(nextLine, 10, fp);
	//this doesn't work
	//if(strcmp(nextLine, "\n") || strcmp(nextLine, "\r\n")
	//  || strcmp(nextLine, "\0")){
	if(nextLine[0] == '\n'){
	    printf("Blank line\n");
	}
	else{
	    nextInt = atoi(nextLine);
	    printf("%d\n", nextInt);
	}
    }

    fclose(fp);

    return 0;
}