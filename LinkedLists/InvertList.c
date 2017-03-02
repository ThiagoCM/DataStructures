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
 
 
node* revert(node* head)
{
    node* aux = head;
    node* after;
    node* previous = NULL;
    while(aux != NULL)
    {
        after = aux->next;
        aux->next = previous;
        previous = aux;
        aux = after;
    }
    return previous;
}
int main()
{
    node* lista;
    int value;
    while(scanf("%d", &value) != EOF)
    {
   lista = add_last(lista, value);
    }
    printList(revert(lista));
   return 0;
}
