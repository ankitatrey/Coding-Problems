#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first = NULL;

void createLL(int a[], int size) {
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = a[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < size; ++i)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

}

void displayLL(struct Node *p) {
	while(p!=NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void rdisplayLL(struct Node *p) {
	if(p!=NULL) {
		printf("%d ", p->data);
		rdisplayLL(p->next);
	}
}


int main(void)
{
	int a[] = {10, 3, 23, 43, 4, 19};
	createLL(a, sizeof(a)/sizeof(a[0]));
	rdisplayLL(first);
	return 0;
}