#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

void free_list();
int add_end(int data);
int add_start(int data);
int add_after(int insert_after_data_loc, int data_loc);
int index_of(int data);
int delete(int index);
int print_list();


#endif
