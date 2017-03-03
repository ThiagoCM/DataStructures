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
 
 
bool subConj(node* first, node* second)
{
    bool result_func;
    node* aux1 = first;
    node* aux2 = second;
    while(aux2 != null)
    {
      while(aux1 != null)
      {
        if(aux1->item != aux2->item) 
        {
          aux1 = aux1->next;
          result_func = false;
        }
        else
        {
          result_func = true;
          break;
        }
      }
      aux2 = aux2->next;
    }
    return result_func;
}
int main()
{
    bool result;
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
    listB= add_last(listB, value);
    B--;
    }
    result = subConj(listA, listB);
   return result;
}
