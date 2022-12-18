#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nextInt;
    char nextLine[10];
	int elfCalories[300] = {0};
    FILE *fp = fopen("day1in.txt", "r");

    if(fp==NULL){
	printf("Error opening file");
	return -1;
    }

	int elfCount = 0;
    while(!feof(fp)){
		fgets(nextLine, 10, fp);

		if(nextLine[0] == '\n'){
			elfCount++;
			printf("Blank line, next elf\n\n");
		}
		else{
			nextInt = atoi(nextLine);
			//add calories for current elf
			elfCalories[elfCount] += nextInt; 
			printf("%d\n", nextInt);
		}	
    }
	
	//find largest calories
	int largestCalories = 0;
	int elfWithMostCalories = 0;
	printf("Elf count: %d\n", elfCount+1);
	for(int i=0; i<=elfCount;i++){
		printf("Elf %d calories: %d\n", i, elfCalories[i]);
		if(elfCalories[i] > largestCalories){
			largestCalories = elfCalories[i];
			elfWithMostCalories = i;
		} 
	}

	printf("Elf with most calories: %d, : %d\n", elfWithMostCalories, largestCalories);

    fclose(fp);

    return 0;
}