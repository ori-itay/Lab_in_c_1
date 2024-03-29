#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

struct Node {
	struct Node* next;
	int data;
};

typedef struct {
	struct Node* head;
}LinkedList;


LinkedList list;

struct Node* allocate(int data, struct Node* next) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

int add_end(int data) {
	if (list.head == NULL) {
		list.head = allocate(data, NULL);
	}
	else {
		struct Node* current = list.head;
		while (current != NULL) {
			if (current->next == NULL) {
				struct Node* new_node = allocate(data, NULL);
				current->next = new_node;
				break;
			}
			current = current->next;
		}
	}
	return 0;
}

int add_start(int data) {
	if (list.head == NULL) {
		list.head = allocate(data, NULL);
	}
	else {
		struct Node* new_node = allocate(data, list.head);
		list.head = new_node;
	}
	return 0;
}

int add_after(int insert_after_data_loc, int data_loc) {
	int found = 0;
	struct Node* current = list.head;
	while (current != NULL) {
		if (current->data == data_loc) {
			found = 1;
			struct Node* new_node = allocate(insert_after_data_loc, NULL);
			if (current->next != NULL) {
				new_node->next = current->next;
			}
			current->next = new_node;
			break;
		}
		current = current->next;
	}
	if (found==0) {
		printf("Error: No such element %d exists!\n", data_loc);
		free_list();
		exit(1);
	}
	return 0;
}

int index_of(int data) {
	int found = 0, index_found = 0;
	struct Node* current = list.head;
	while (current != NULL) {
		if (current->data == data) {
			found = 1;
			break;
		}
		index_found++;
		current = current->next;
	}
	if (found) {
		printf("%d\n", index_found);
	}
	else {
		printf("-1\n");
	}
	return 0;
}

int length_of_list(){
	int counter=0;
	struct Node* current = list.head;
	while (current != NULL){
		counter++;
		current=current->next;
	}
	return counter;
}

int delete_first_element() {
	if (list.head == NULL) {
		printf("Error: no such index exists!\n");
		free_list();
		exit(1);
	}
	else {
		struct Node* to_be_deleted = list.head;
		list.head = list.head->next;
		free(to_be_deleted);
		return 0;
	}
}

int delete_other_elements(int index) {
	int counter;
	struct Node* father_of_index = list.head;
	for (counter = 0; counter < index - 1; counter++) {
		if (father_of_index == NULL || father_of_index->next == NULL) {
			printf("Error: no such index exists!\n");
			free_list();
			exit(1);
		}
		father_of_index = father_of_index->next;
	}
	struct Node* deleted_node = father_of_index->next;
	father_of_index->next = father_of_index->next->next;
	free(deleted_node);
	return 0;
}

int delete(int index) {
	int length = length_of_list();
	if (index >= length){
		printf("Error: no such index exists!\n");
		free_list();
		exit(1);
	}
	if (index == 0) {
		return delete_first_element();
	}
	else {
		return delete_other_elements(index);
	}
}

int print_list() {
	printf("[");
	struct Node* current = list.head;
	while (current != NULL) {
		if (current->next == NULL) {
			printf("%d", current->data);
		}
		else {
			printf("%d, ", current->data);
		}
		current = current->next;
	}
	printf("]\n");
	return 0;
}

void free_list() {
	struct Node* deleted = list.head;
	while (deleted != NULL) {
		struct Node* after_deleted = deleted->next;
		free(deleted);
		deleted = after_deleted;
	}
}
