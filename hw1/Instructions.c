#include <stdio.h>

#include "Instructions.h"
#include "LinkedList.h"

int length(char* string){
	int length=0;
	while (string[length]!='\0'){
		length++;
	}
	return length;
}

void toLowerCase(char line[]){
	int len = length(line);
	for (int i=0 ; i < len ; i++){
		char letter = line[i];
		if ((letter < 123 && letter > 96) /* if a lowercase or a valid number or a underscore */
				|| (letter < 58 && letter > 47) || letter==95 ){
			continue;
		}
		else {
			line[i]=line[i]+32; /* from Uppercase to Lowercase */
		}
	}
}

void get_command(char line[]){

}

void fetch(){
	char command[SIZE]={'\0'};
	get_command(command);
	toLowerCase(command);



}

int execute(){

	return 0;
}

int fetch_and_exec_cmd(){
	fetch();
	execute();

	return 0;
}

int Exit(){
	free_list();
	return 1;
}
