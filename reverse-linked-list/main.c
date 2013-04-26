#include "stdlib.h"
#include "stdio.h"
#include "main.h"

/**
 * Print the integers in the Items in the LinkedList
**/
void printLinkedList(Item *list) {
	Item *current = list;
	while(current != NULL) {
		printf("v = %d, ", current->v);
		current = current->next;
	}
	printf("\n");
}

/**
 * Adds an Item to the front of a LinkedList
**/
void addToLinkedList (Item **list, Item *item) {
	item->next = *list;
	*list = item;
}

/**
 * Main function,
 * Allocates a LinkedList with 10 items, prints it to show the order,
 * calls reverseLinkedList to reverse it, and prints it again to see
 * if the order indeed was reversed.
**/
void main () {
	int i;
	Item *List = NULL;
	for (i=0; i<10; i++) {
		Item *item = malloc(sizeof(Item));
		item->v = 10 - i;
		addToLinkedList(&List, item);
	}			
	
	printLinkedList(List);

	Item *revList = reverseLinkedList(List);

	printLinkedList(revList);

}

