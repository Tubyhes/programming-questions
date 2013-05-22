#include "stdlib.h"
#include "main.h"

Item *reverseLinkedList (Item *list) {
	Item *first = NULL;

  while (list != NULL) {
    Item *current = list;
    list = list->next;
    current->next = first;
    first = current;
  }
}
