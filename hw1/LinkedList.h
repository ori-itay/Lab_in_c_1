/*
 * LinkedList.h
 *
 *  Created on: Mar 7, 2019
 *      Author: Ori
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct{
	struct Node* next;
	int data;
}Node;

typedef struct{
	Node* head;
}LinkedList;



int fetch_and_exec_cmd();
void fetch();
void exec();


/****************************************/

int Add_end(int index);
int Add_start(int index);
int Add_after(int insert_after_data_loc, int data_loc);
int Index(int i);
int Del(int index);
int Print();
int Exit();



#endif /* LINKEDLIST_H_ */