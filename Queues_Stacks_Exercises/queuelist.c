#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;
typedef struct node Node;

struct node {
  int item;
  int size;
  Node *next_node;
};

typedef struct stack{
    Node* top;
};

Stack* create_stack() {
  Stack *stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, int item, int size) {
  Node *new_top = (Node*) malloc(sizeof(Node));
  new_top->item = item;
  new_top->size = size;
  new_top->next_node = stack->top;
  stack->top = new_top;
}

int pop(Stack *stack) {
  if (is_empty(stack)) return -1;

  Node *return_top = (Node*) malloc(sizeof(Node));
  int item = stack->top->item;
  stack->top = stack->top->next_node;
  free(return_top);
  return item;
}

int peek(Stack *stack) {
  if(is_empty(stack)) return -1;

  else return stack->top->item;
}

int is_empty(Stack *stack) {
  return (stack->top == NULL);
}

int main() {
    char entrada[10000];
    char valor[10000];
    int i, j;
    int function = 0, tamanho = 1;
    int contador_LF = 0, contador_POP = 0;;
    int teste;
    Stack* pilha = create_stack();

    while(1){

      entrada[i] = getchar();

      if((int) entrada[i] == 32) {
        entrada[i] = getchar();
      }

      if((int) entrada[i] == 10) {
        contador_LF++;
        if(contador_LF == 2) {
          function = 0;
          contador_LF = 0;
          tamanho = 0;
        }
      }

      if((int) entrada[i] == -1) {
        printf("acabou!\n"); //final
        return 0;
      }

      if((int) entrada[i-3] == 80 && (int) entrada[i-2] == 85
          && (int) entrada[i-1] == 83 && (int) entrada[i] == 72) {
        function = 1;
      }

      if((int) entrada[i-2] == 80 && (int) entrada[i-1] == 79 &&
         (int) entrada[i] == 80) {
        printf("Entrei no POP!\n");
        function = 2;
      }

      if(function == 1 && (int) entrada[i] != 10) {
        if(entrada[i] - 48 != 24) {
          push(pilha, entrada[i] - 48, tamanho++);
        }
      }

      if(function == 2 ) {
        tamanho = pilha->top->size;
        for(j = 1; j < tamanho;) {
          valor[j] = pop(pilha);
          teste = peek(pilha);
          printf("V:%d", valor[j]);
          printf("T:%d", teste);
          j++;
        }
      //  for(j = 1; j < tamanho+1; j++) {
  //      printf("%d ", valor[j]);
  //      }
        printf("\n");
      }
      i++;
    }

    return 0;
}
