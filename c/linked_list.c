#include <stdio.h>

struct Node {
	int n;
	struct Node *next;
};

struct Node head = NULL;
int size = 0;

void
addNode(int n) {
	struct Node tmp;
	tmp.n = n;
	tmp.next = head;
	head = &tmp;
}

