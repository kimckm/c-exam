#include <stdio.h>
#include <stdlib.h>
#include "adlist.h"

adlist *adlist_create(void)
{
	adlist *list;

	if ((list = malloc(sizeof(*list))) == NULL) {
		return NULL;
	}
	list->head = list->tail = NULL;
	list->len = 0;

	return list;
}

adlist *adlist_push_node(adlist *list, void *value)
{
	adlist_node *node;

	if ((node = malloc(sizeof(*node))) == NULL) {
		return NULL;
	}
	node->value = value;
	if (list->len == 0) {
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	} else {
		node->prev = list->tail;
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	}
	list->len++;
	return list;
}

static void node_print(adlist_node *node)
{
	printf("%s\n", node->value);
	if (node->next != NULL) {
		node_print(node->next);
	}
}

void adlist_print(adlist *adlist)
{
	node_print(adlist->head);
}

int main(int argc, char const *argv[]) {
	adlist *list = adlist_create();
	adlist_push_node(list, "a");
	adlist_push_node(list, "b");
	adlist_push_node(list, "c");
	adlist_print(list);
	return 0;
}
