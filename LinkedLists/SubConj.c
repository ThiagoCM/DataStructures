#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *next;
};typedef struct node node;


node* create(int value)
{
    node* p = (node*) malloc(sizeof(node));
    p->item = value;
    return p;
}

node* add_last(node* head, int value)
{
    node* new_node = create(value);
    node* previous = NULL;
    node* aux = head;
    
    while(aux != NULL)
    {
        previous = aux;
        aux = aux->next;
    }
    if(previous == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        new_node->next = previous->next;
        previous->next = new_node;
    }
    return head;
    
}
 
void printList(struct node *node)
{
  while (node != NULL)
  {
     printf("%d ", node->item);
     node = node->next;
  }
}
 
 
int subConj(node* A, node* B)
{
    node* aux = B;
    while(aux != null)
    {
      if(aux->item != 
    }
    
}
int main()
{
    node* listA;
    node* listB;
    int A, B, value;
    scanf("%d", &A);
    while(A > 0)
    {
    scanf("%d", &value);
    listA = add_last(listA, value);
    A--;
    }
    scanf("%d", &B);
    while(B > 0)
    {
    scanf("%d", &value);
    listA = add_last(listA, value);
    B--;
    }
    printList(revert(lista));
   return 0;
}
