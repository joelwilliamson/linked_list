/* Return a pointer to the object containing a field */
#define container_of(ptr_to_field,object_name,field_name) \
	(ptr_to_field?(object_name*)(((void*)ptr_to_field) - (void*)&(((object_name*)0)->field_name)):NULL)

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
	(container_of((current_element)->list_name.next,element_type,list_name))

#define prev_element(current_element,element_type,list_name) \
	(container_of((current_element)->list_name.prev,element_type,list_name.prev))

struct list_node * find_last_node(struct list_node * current_node);

/*
 * Return a pointer to the last element in the list
 */
#define find_last(current_element,element_type,list_name) \
	(container_of(find_last_node((current_element)->list_name),element_type,list_name))

struct list_node * find_prev_node(struct list_node * current_node);

/*
 * Return a pointer to the first element in the list
 */
#define find_first(current_element,element_type,list_name) \
	(container_of(find_first_node((current_element)->list_name),element_type,list_name))

/*
 * Insert the new element after the last element and return a pointer to it
 * Requires a pointer to the current element
 */
#define append(current_element,element_type,list_name,ptr_to_new_element) \
	(find_last_node(&(current_element)->list_name)->next = &(ptr_to_new_element->list_name))


#define foreach(current_element,element_type,list_name,temp_name) \
	for (element_type * temp_name = current_element; \
		temp_name != NULL; \
		temp_name = next_element(temp_name,element_type,list_name))
