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

int count(struct Node *p) {
	if(p == 0)
		return 0; 
	else 
		return count(p->next) + 1;
}

int sum(struct Node *p) {
	if(p == 0)
		return 0; 
	else 
		return sum(p->next) + p->data;
}

// recursive function to find out the maximum element in the LL
int maxLL(struct Node *p) {
	int x = 0;
	if(p == 0) 
		return MIN_INT;
	else {
		x = maxLL(p->next);
		if (x > p->data) return x;
		return p->data;
	}
}


int main(void)
{
	int a[] = {10, 3, 23, 43, 4, 19};
	createLL(a, sizeof(a)/sizeof(a[0]));
	displayLL(first);
	printf("\n%d\n", count(first));
	printf("%d\n", sum(first));
	printf("%d\n", maxLL(first));
	return 0;
}