#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"


int Add_end(int index);
int Add_start(int index);
int Add_after(int insert_after_data_loc, int data_loc);
int Index(int i);
int Delete(int index);
int Print();

LinkedList list;


int Add_end(int data){
	if (list.head==NULL){
		list.head=(struct Node*)malloc(sizeof(struct Node));
		list.head->data=data;
		list.head->next=NULL;
	}
	else{
		struct Node* temp = list.head;
		while (temp!=NULL){
			if (temp->next==NULL){
				struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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
		list.head=(struct Node*)malloc(sizeof(struct Node));
		list.head->data=data;
		list.head->next=NULL;
	}
	else{
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->data = data;
		new_node->next = list.head;
		list.head=new_node;
	}
	return 0;
}
int Add_after(int insert_after_data_loc, int data_loc){
	int found=0;
	struct Node* temp = list.head;
	while (temp!=NULL){
		if (temp->data==data_loc){
			found=1;
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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
		printf("Error: No such element %d exists!\n", data_loc);
		return 1;
	}
	return 0;
}

int Index(int data){
	int found=0,index_found=0;
	struct Node* temp = list.head;
	while (temp!=NULL){
		if (temp->data==data){
			found = 1;
			break;
		}
		index_found++;
		temp=temp->next;
	}
	if (found){
		printf("%d\n", index_found);
	}
	else{
		printf("-1\n");
	}
	return 0;
}

int delete_first_element(){
	if (list.head==NULL){
		printf("Error: no such index exists!\n");
		return 1;
	}
	else{
		struct Node* to_be_deleted = list.head;
		list.head=list.head->next;
		free(to_be_deleted);
		return 0;
	}
}

int delete_element(int index){
	struct Node* father_of_index=list.head;
	for (int counter=0 ; counter < index-1 ; counter++){
		if (father_of_index==NULL || father_of_index->next==NULL){
			printf("Error: no such index exists!\n");
			return 1;
		}
		father_of_index=father_of_index->next;
	}
	struct Node* deleted_node = father_of_index->next;
	father_of_index->next=father_of_index->next->next;
	free(deleted_node);
	return 0;
}

int Delete(int index){
	if (index==0){
		return delete_first_element();
	}
	else{
		return delete_element(index);
	}
}

int Print(){
	printf("[");
	struct Node* current = list.head;
	while (current!=NULL){
		if (current->next==NULL){
			printf("%d", current->data);
		}
		else{
			printf("%d, ", current->data);
		}
		current=current->next;
	}
	printf("]\n");
	return 0;
}

void free_list(){
	struct Node* deleted=list.head;
	while (deleted!=NULL){
		struct Node* after_deleted = deleted->next;
		free(deleted);
		deleted=after_deleted;
	}
}

