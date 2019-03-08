#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


struct Node {
	struct Node* next;
	int data;
};

typedef struct {
	struct Node* head;
}LinkedList;

void free_list();


#endif /* LINKEDLIST_H_ */
