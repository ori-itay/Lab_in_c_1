#include <stdio.h>
#include <stdlib.h>
#include "Flow.h"
#include "LinkedList.h"

#define MAX_LINE_LEN 100
#define MAX_WORD_LEN 10
#define MAX_WORDS_IN_COMMAND 3

//private functions headers
int string_compare(char str1[], char str2[]);
int get_string_length(char* string);
void str_to_lowercase(char line[]);
void parse(char command[MAX_LINE_LEN], char parsedCommand[MAX_WORDS_IN_COMMAND][MAX_WORD_LEN]);
int get_command_num(char parsedCommand[MAX_WORDS_IN_COMMAND][MAX_WORD_LEN]);
int execute(int commandNum, int i, int j);
int fetch_and_exec_cmd();


int main(void) {
	while (fetch_and_exec_cmd()) {}
	return 0;
}

int fetch_and_exec_cmd() {
	int command_num = -1;
	char command[MAX_LINE_LEN] = { '\0' };
	char parsedCommand[MAX_WORDS_IN_COMMAND][MAX_WORD_LEN] = { { '\0' } };
	if (fgets(command, MAX_LINE_LEN, stdin) == NULL) {
		return 0;
	}
	str_to_LowerCase(command);
	parse(command, parsedCommand);
	command_num = get_command_num(parsedCommand);
	execute(command_num, atoi(parsedCommand[1]), atoi(parsedCommand[2]));
	return 1;
}

int get_string_length(char* string) {
	int length = 0;
	while (string[length] != '\0') {
		length++;
	}
	return length;
}

void str_to_lowercase(char line[]) {
	int len = length(line);
	for (int i = 0; i < len; i++) {
		char letter = line[i];
		if (letter >= 65 && letter <= 90) {
			line[i] = line[i] + 32; /* from Uppercase to Lowercase */
		}
	}
}

int Exit() {
	free_list();
	exit(0);
}


void parse(char command[MAX_LINE_LEN], char parsedCommand[MAX_WORDS_IN_COMMAND][MAX_WORD_LEN])
{
	int i = 0, letter = 0, word_num = 0;

	for (i = 0; i < MAX_LINE_LEN; i++) {
		if (command[i] == '\r' || command[i] == '\n' || command[i] == EOF) { // end of command
			break;
		}
		else if (command[i] != ' ' && command[i] != '\t') { //curr char is part of a word
			parsedCommand[word_num][letter++] = command[i];
		}
		else { // word ended
			parsedCommand[word_num][letter] = '\0'; //add end of string char
			letter = 0; // initialize letter index
			word_num++;
		}
	}
	return;
}


int get_command_num(char parsedCommand[MAX_WORDS_IN_COMMAND][MAX_WORD_LEN]) {
	if (string_compare(parsedCommand[0], "add_end") == 0 && string_compare(parsedCommand[1], "") != 0)
		return 1;
	if (string_compare(parsedCommand[0], "add_start") == 0 && string_compare(parsedCommand[1], "") != 0)
		return 2;
	if (string_compare(parsedCommand[0], "add_after") == 0 && string_compare(parsedCommand[1], "") != 0
		&& string_compare(parsedCommand[2], "") != 0)
		return 3;
	if (string_compare(parsedCommand[0], "index") == 0)
		return 4;
	if (string_compare(parsedCommand[0], "del") == 0 && string_compare(parsedCommand[1], "") != 0)
		return 5;
	if (string_compare(parsedCommand[0], "print") == 0)
		return 6;
	if (string_compare(parsedCommand[0], "exit") == 0)
		return 7;
	return -1;/*no valid command*/
}


int execute(int commandNum, int i, int j) {
	switch (commandNum) {
	case -1:
		printf("ERROR: invalid command\n");
		break;
	case 0: /*Blank line, ignore this 'command'*/
		break;
	case 1:
		add_end(i);
		break;
	case 2:
		add_start(i);
		break;
	case 3:
		add_after(i, j);
		break;
	case 4:
		index_of(i);
		break;
	case 5:
		delete(i);
		break;
	case 6:
		print_list();
		break;
	case 7:
		Exit();
	}
	return 1;
}

/*returns 0 if both strings are identical, orherwise returns 1.*/
int string_compare(char str1[], char str2[]) {
	int len1, len2, i;

	len1 = length(str1);
	len2 = length(str2);
	if (len1 != len2) {
		return 1;
	}
	for (i = 0; i < len1; i++) {
		if (str1[i] != str2[i]) {
			return 1;
		}
	}
	return 0;
}