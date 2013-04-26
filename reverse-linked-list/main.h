
#ifndef __MAIN_H__
#define __MAIN_H__


/**
 * The LinkedList Item struct declaration
**/
struct Item_S {
	int v;
	struct Item_S *next;
};
typedef struct Item_S Item;

/**
 * Forward declaration of the reverseLinkedList function
**/
Item *reverseLinkedList (Item *list);

#endif
