#include "linked_list.h"



struct list_node * find_last_node(struct list_node * current_node)
{
	while (current_node->next) current_node = current_node->next;
	return current_node;
}

struct list_node * find_first_node(struct list_node * current_node)
{
	while (current_node->prev) current_node = current_node->prev;
	return current_node;
}
