#include <sys/queue.h>
#include <stdio.h>
int main() {
	struct node {
		char c;
		LIST_ENTRY(node) entries;
	};
	LIST_HEAD(my_list, node) head;
	LIST_INIT(&head);
	struct node foo[10];
	for (int i = 0; i < 10; ++i) {
		foo[i].c = i + '0';
		LIST_INSERT_HEAD(&head, &foo[i], entries);
	}
	struct node *item;
	LIST_FOREACH(item, &head, entries) {
		printf("%c\n", item->c);
	}
	return 0;

}
