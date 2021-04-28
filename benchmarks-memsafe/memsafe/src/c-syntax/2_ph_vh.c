/*Pointers (heap) pointing to
  variables (heap).*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *create_node(int value) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

struct node *create() {
    int i = 0;
    struct node *head, *p;
    head = p = create_node(i);
    for (i = 1; i < 10; i++) {
        p->next = create_node(i);
        printf("created node %d: %d\n", i, p->next->value);
        p = p->next;
    }
    return head;
}

void remove_list(struct node *head) {
  if(head == NULL) return;
  if(head->next != NULL)
  {
    remove_list(head->next);
    head->next = NULL;
  }
  free(head);
}

int main()
{
    int ret;
    struct node *head = create();

    remove_list(head->next);
    ret = head->next->value; /*temporal error*/
    head->next = NULL;
    remove_list(head);

    return 0;
}
