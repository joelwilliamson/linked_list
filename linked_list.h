/* Return a pointer to the object containing a field */
#define container_of(ptr_to_field,field_name,object_name) \
	(object_name*)(((void*)ptr_to_field) - (void*)&(((object_name*)0)->field_name))

struct list_node {
	struct list_node * next;	/* The next node in the list, NULL if this node is last */
	struct list_node * prev;	/* The previous node in the list */
};

/* 
 * Return a pointer to the next structure in the list
 * element type is the type of the containers in the list
 * list_name is the name of the list_node field in each element
 */
#define next_element(current_element,element_type,list_name) \
	container_of(current_element.list_name.next,list_name.next,element_type)

#define prev_element(current_element,element_type,list_name) \
	container_of(current_element.list_name.prev,list_name.prev,element_type)

struct list_node * find_last_node(struct list_node * current_node);

/*
 * Return a pointer to the last element in the list
 */
#define find_last(current_element,element_type,list_name) \
	container_of(find_last_node(current_element.list_name),list_name,element_type)
