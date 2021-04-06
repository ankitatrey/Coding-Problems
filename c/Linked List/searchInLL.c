#include<stdio.h>
#include<stdlib.h>

#define MIN_INT -32676

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

int lsearch(struct Node *p, int key) {
	while(p) {
		if (p->data == key) 
			return 1;
		p = p->next;
	}
	return 0;
}

struct Node * rsearch(struct Node *p, int key) {
	if (p == NULL)
		return NULL;
	if(p->data == key) 
		return p;
	return rsearch(p->next, key);	
}

int main(void)
{
	struct Node *temp;
	int a[] = {10, 3, 23, 43, 4, 19};
	createLL(a, sizeof(a)/sizeof(a[0]));
	displayLL(first);
	printf("\n%d\n", lsearch(first, 23));

	temp = rsearch(first, 2);
	printf("%d\n", temp->data);

	return 0;
}