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
int test_append()
{
	struct int_list head = {5,{NULL,NULL}};

	return 1;
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
