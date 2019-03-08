#include <stdio.h>

#include "Instructions.h"
#include "LinkedList.h"


//private functions headers
int length(char* string);
void toLowerCase(char line[]);
void parse(char command[MAXLINELEN], char parsedCommand[MAXWORDSINCOMMAND][MAXWORDLEN]);
int getCommandNum(char parsedCommand[MAXWORDSINCOMMAND][MAXWORDLEN]);
int execute(int commandNum, int i, int j);



int fetch_and_exec_cmd() {
	int command_num = -1;
	char command[MAXLINELEN] = { '\0' };
	char parsedCommand[MAXWORDSINCOMMAND][MAXWORDLEN] = { { '\0' } };

	if (fgets(command, MAXLINELEN, stdin) == NULL) {
		return 0;
	}
	toLowerCase(command);
	//printf("entered command is : %s\n", command);
	parse(command, parsedCommand);
	//printf("parsed_command[0]: %s, parsed_command[1]: %s, parsed_command[2]: %s. \n", parsedCommand[0], parsedCommand[1], parsedCommand[2]);
	command_num = getCommandNum(parsedCommand);
	execute(command_num, atoi(parsedCommand[1]), atoi(parsedCommand[2]) == 1);
	return 1;
}


int length(char* string) {
	int length = 0;
	while (string[length] != '\0') {
		length++;
	}
	return length;
}

void toLowerCase(char line[]) {
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



/** parse
 * -------
 * Parses a full line of command from user (up to MAXLINELEN chars)
 * to known commands.
 *
 * @param char command[] - A string which is user's 'raw' input command.
 * @param char parsedCommand[][] - Array of MAXWORDSINCOMMAND strings, which is the user's command parsed into words/numbers.
 *
 * @return - void.
 */
void parse(char command[MAXLINELEN], char parsedCommand[MAXWORDSINCOMMAND][MAXWORDLEN])
{
	int i = 0, letter = 0, word_num = 0;

	for (i = 0; i < MAXLINELEN; i++) {
		if (command[i] == '\r' || command[i] == '\n' || command[i] == EOF) { // end of command
			break;
		}
		else if (command[i] != ' ' && command[i] != '\t') { //curr char is part of a word
			parsedCommand[word_num][letter++] = command[i];
		}
		else { // word ended
			parsedCommand[word_num][letter] = '\0'; //end of string char
			letter = 0; // initialize letter index
			word_num++;
		}
	}
	return;
}


/** getCommandNum
 * ----------------
 * Determines the number of command which is currently in parsedCommand.
 *
 * @param char parsedCommand[][] - Array of MAXWORDSINCOMMAND strings, which is the user's command parsed into words/numbers.
 *
 * @return - int: The number of the command represented in parsedCommand:
 * -1: invalid command, 1: add_end i , 2: add_start i , 3: add_after i j, 4: index,
 * 5: del index , 6: print, 7: exit.
 */
int getCommandNum(char parsedCommand[MAXWORDSINCOMMAND][MAXWORDLEN]) {
	if (strcmp(parsedCommand[0], "add_end") == 0 && strcmp(parsedCommand[1], "") != 0)
		return 1;
	if (strcmp(parsedCommand[0], "add_start") == 0 && strcmp(parsedCommand[1], "") != 0)
		return 2;
	if (strcmp(parsedCommand[0], "add_after") == 0 && strcmp(parsedCommand[1], "") != 0 && strcmp(parsedCommand[2], "") != 0)
		return 3;
	if (strcmp(parsedCommand[0], "index") == 0)
		return 4;
	if (strcmp(parsedCommand[0], "del") == 0 && strcmp(parsedCommand[1], "") != 0)
		return 5;
	if (strcmp(parsedCommand[0], "print") == 0)
		return 6;
	if (strcmp(parsedCommand[0], "exit") == 0)
		return 7;
	return -1;/*no valid command*/
}


/** execute:
 * ------------
 * This function executing the proper function according to the passed commandNum.
 *
 * @param int commandNum - The number (index) of the command to be executed.
 * @param char parsedCommand[][] - Array of MAXWORDSINCOMMAND strings, which is the user's command parsed into words/numbers.
 *
 * @return: void.
 */
int execute(int commandNum, int i, int j) {
	switch (commandNum) {
	case -1:
		printf("ERROR: invalid command\n");
		break;
	case 0: /*Blank line, ignore this 'command'*/
		break;
	case 1:
		Add_end(i);
		break;
	case 2:
		Add_start(i);
		break;
	case 3:
		Add_after(i, j);
		break;
	case 4:
		Index_of(i);
		break;
	case 5:
		Delete(i);
		break;
	case 6:
		Print_list();
		break;
	case 7:
		Exit();
	}

	return 1;
}