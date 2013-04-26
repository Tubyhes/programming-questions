#include "stdlib.h"
#include "main.h"

Item *reverseLinkedList (Item *list) {
	Item *first = list;
	Item *new_list = list->next;
	first->next = NULL;
	
	Item *reversed_new_list = NULL;
	if (new_list != NULL) {
		reversed_new_list = reverseLinkedList(new_list);	
		Item *temp = reversed_new_list;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = first;
		return reversed_new_list;
	}
	
	return first;
}
