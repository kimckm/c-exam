#ifndef __ADLIST_H__
#define __ADLIST_H__

typedef struct adlist_node {
	struct adlist_node *prev;
	struct adlist_node *next;
	void *value;
} adlist_node;

typedef struct adlist_iter {
	adlist_node *next;
	int direction;
} adlist_iter;

typedef struct list {
	adlist_node *head;
	adlist_node *tail;
	unsigned long len;
} adlist;

adlist *adlist_create(void);
adlist *adlist_push_node(adlist *adlist, void *value);
void adlist_print(adlist *adlist);

#endif /* __ADLIST_H__ */
