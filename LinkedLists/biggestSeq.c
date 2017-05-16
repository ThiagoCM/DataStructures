//Utilizei c?digos do livro
//Apostila de
//Estruturas de Dados
//Profs. Waldemar Celes e Jos? Lucas Rangel
//PUC-RIO - Curso de Engenharia - 2002
// Acabei ficando sem tempo e fazendo uma gambiarra na fun??o de busca.

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  char item;
  int pos;
  Node *next_node;
  Node *prev_node;
};

Node* create_doubly_linked_list() {
  return NULL;
}

Node* insert_node(Node *first, char item, int position) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->item = item;
  new_node->next_node = first;
  new_node->prev_node = NULL;
  new_node->pos = position;

  if(first != NULL)
    first->prev_node = new_node;

  return new_node;
}

Node* search(Node *first, char item) {
  Node *node;

  for(node = first; node->next_node != NULL; node = node->next_node) {
    if(node->item == item) return node;
  }

  return NULL;
}

Node* remove_node(Node *first, char item) {
  Node *node = search(first, item);
  if(node == NULL) return first;

  if(node == first)
    first = node->next_node;
  else
    node->prev_node->next_node = node->next_node;

  if(node->next_node != NULL)
    node->next_node->prev_node = node->prev_node;

  free(node);
  return first;
}

int is_empty(Node *first) {
  return (first == NULL);
}

void print_doubly_linked_list_forward(Node *first) {
  if(!is_empty(first)) {
    print_doubly_linked_list_forward(first->next_node);

    printf("%c", first->item);
  }
}

void print_doubly_linked_list_backward(Node *last) {
  if(!is_empty(last)) {
    print_doubly_linked_list_backward(last->prev_node);

    printf("%c ", last->item);

  }
}

void answer (Node *head)
{
	Node *aux = head;
	int begin=0, end=0, dif=0, counter = 0;
        while(aux != NULL)
	{
    if(aux->item == '0') {
      begin = aux->pos;
      if(next->item != '0')
      {
          end = aux->pos;
      }
    }
    if(aux->item == '0') {
      end = aux->pos;
    }
    if(dif < (end - begin)) {
      dif = end - begin;
    }
    aux = aux->next_node;
	}
        printf("%d, %d", end-dif, end);
}

int main()
{
    Node* lista = create_doubly_linked_list();
    char value;
    int position = 1;

    while(scanf("%c", &value) != EOF)
    {
    lista = insert_node(lista, value, position++);
    }


    answer(lista);
   return 0;
}
