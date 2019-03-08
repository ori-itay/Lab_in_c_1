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
int Add_end(int data);
int Add_start(int data);
int Add_after(int insert_after_data_loc, int data_loc);
int Index_of(int data);
int Delete(int index);
int Print_list();




#endif /* LINKEDLIST_H_ */
