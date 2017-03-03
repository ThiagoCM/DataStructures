
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
  int item;
  struct node *next;
};typedef struct node node;

node* create_linked_list()

{

return NULL;

}

node* add(node *head, int item)

{

node *new_node = (node*) malloc(sizeof(node));

new_node->item = item;

new_node->next = head;

return new_node;

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
    bool result_func = false;
    node* aux2 = second;
    while(aux2 != NULL)
    {
	node* aux1 = first;
      while(aux1 != NULL)
      {
        if(aux1->item != aux2->item) 
        {
          aux1 = aux1->next;
        }
        else if(aux1->item == aux2->item)
        {
          result_func = true;
          break;
        }
	if(aux1 == NULL)
	{
	  result_func = false;
	  break;	
	}
      }
      aux2 = aux2->next;
      if(result_func == false) break;
    }
    return result_func;
}
void main()
{
    bool result;
    node* listA = create_linked_list();
    node* listB = create_linked_list();
    int A, B, value;
    scanf("%d", &A);
    while(A > 0)
    {
    	scanf("%d", &value);
    	listA = add(listA, value);
    	A--;
    }
    scanf("%d", &B);
    while(B > 0)
    {
    	scanf("%d", &value);
    	listB= add(listB, value);
    	B--;
    }
    result = subConj(listA, listB);
    printf("%d", result);
}
