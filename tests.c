#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct three_ints {
	int a,b,c;
};

int test_container_of()
{
	struct nested_struct {
		struct three_ints t1;
		struct three_ints t2;
	} ns;
	struct three_ints t;
	t.a = 4;
	t.b = 5;
	t.c = 6;
	struct three_ints * tp = container_of(&(t.b),struct three_ints,b);

	struct nested_struct * nsp = container_of(&(ns.t2.a),struct nested_struct,t2.a);
	ns.t1.a = 0xa;

	return tp->a == t.a && tp->b == t.b && tp->c == t.c && nsp->t1.a == ns.t1.a;
}

struct int_list {
	int data;
	struct list_node list;
};

void print_int_list_node(char* node_name, struct int_list * node)
{
	printf("%s = {%d,{%p,%p}} @ %p\n",node_name,node->data,node->list.next,node->list.prev,node);
}

int test_append()
{
	struct int_list head = {0,{NULL,NULL}};
	struct int_list * pil1 = malloc(sizeof(*pil1));
	pil1->data = 1;
	pil1->list.next = NULL;
	struct int_list * pil2 = malloc(sizeof(*pil2));
	pil2->data = 2;
	pil2->list.next = NULL;

	append(&head,struct int_list,list,pil1);
	append(&head,struct int_list,list,pil2);

	print_int_list_node("head",&head);
	print_int_list_node("pil1",pil1);
	print_int_list_node("pil2",pil2);

	printf("%p\n",next_element(pil2,struct int_list,list));

	foreach(&head,struct int_list,list,elem) {
		printf("%d\n",elem->data);
	}

	return next_element(&head,struct int_list,list)->data == pil1->data;
}


int main()
{
	int test_result = 1;
	test_result &= test_container_of();
	test_result &= test_append();
	if (test_result) printf("All tests passed.\n");
	else printf("A test failed.\n");
	return 0;
}
