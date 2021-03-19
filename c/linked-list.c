#include<stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*first=NULL;

void create(int arr[], int n) {
  int i;
  struct Node *p,*last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;

  for(i=1;i<n; i++) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = arr[i];
    p->next = NULL;
    last->next = p;
    last = p;
  }
}

void display(struct Node *p) {
  if(p != NULL) {
    printf(" %d ", p->data);
    display(p->next);
  }
}

int main(void){
  int arr[10] = {2,12,3,43,43,1,8,56,4,98};
  create(arr, 10);
  display(first);
}
