#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

LinkedList list;



void fetch(){
	char command[100]={'\0'};
	get_command(command);
	toLowerCase(command);



}
void get_command(char line[]){

}

void toLowerCase(char line[]){
	int len = strlen(line);
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


int Add_end(int data){
	if (list.head==NULL){
		list.head=(Node*)malloc(sizeof(Node));
		list.head->data=data;
		list.head->next=NULL;
	}
	else{
		Node* temp = list.head;
		while (temp!=NULL){
			if (temp->next==NULL){
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->data=data;
				new_node->next=NULL;
				temp->next=new_node;
			}
		}
	}
	return 0;

}
int Add_start(int data){
	if (list.head==NULL){
		list.head=(Node*)malloc(sizeof(Node));
		list.head->data=data;
		list.head->next=NULL;
	}
	else{
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = data;
		new_node->next = list.head;
		list.head=new_node;
	}
	return 0;
}
int Add_after(int insert_after_data_loc, int data_loc){
	int found=0;
	Node* temp = list.head;
	while (temp!=NULL){
		if (temp->data==data_loc){
			found=1;
			Node* new_node = (Node*)malloc(sizeof(Node));
			new_node->data = insert_after_data_loc;
			if (temp->next==NULL){
				new_node->next=NULL;
			}
			else{
				new_node->next = temp->next;
			}
			temp->next=new_node;
		}
	}
	if (!found){
		printf("Error: No such element j exists!\n");
		return 1;
	}
	return 0;
}
int Index(int i);
int Del(int index);
int Print();
int Exit();
