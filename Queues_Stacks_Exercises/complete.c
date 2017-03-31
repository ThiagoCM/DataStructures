#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    ();

//Libera a memória do conteúdo e do próprio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();

  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear(deque);
    print(deque);
 
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    //destruct(deque);
       
	return 0;
}

node_t* node_new(int value)
{
	node_t* new = (node_t*) malloc(sizeof(node_t));
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	return new;
}

deque_t* construct()
{
	deque_t* new = (deque_t*) malloc(sizeof(deque_t));
	new->front = NULL;
	new->rear = NULL;
	new->size = 0;
	return new;
}

void destruct(deque_t *deque)
{
	free(deque);
}

int size(deque_t *deque)
{
	return deque->size;
}

bool empty(deque_t *deque)
{
	if(deque->size == 0 || deque->rear == NULL || deque->front == NULL)	return true;
	else	return false;
}

int front(deque_t *deque)
{
	if(deque->size == 0) return empty(deque);
	else return deque->front->value;
}

int      rear(deque_t *deque)
{
	if(deque->size == 0) return empty(deque);
	else return deque->rear->value;
}

void     enqueue_rear(deque_t *deque, int value)
{
	node_t* new = node_new(value);
	if(empty(deque))
	{
		deque->rear = new;
		deque->front = new;
		deque->size = 1;
	}
	else
	{
		deque->rear->next = new;
		new->prev = deque->rear;
		deque->rear = new;
		deque->size++;
	}
}

void     enqueue_front(deque_t *deque, int value)
{
	node_t* new = node_new(value);
	if(empty(deque))
	{
		deque->front = new;
		deque->rear = new;
		deque->size = 1;
	}
	else
	{
		deque->front->prev = new;
		new->next = deque->front;
		deque->front = new;
		deque->size++;
	}
}

void     dequeue_rear(deque_t *deque)
{
	node_t* aux = deque->rear;
	if(empty(deque)) return;
	else{
		deque->rear = aux->prev;
		free(aux);
		deque->rear->next = NULL;
	}
}

void     dequeue_front(deque_t *deque)
{
	node_t* aux = deque->front;
	if(empty(deque)) return;
	else{
		deque->front = aux->next;
		free(aux);
	}
}

void     erase(deque_t *deque)
{
	deque->front = NULL;
	deque->rear = NULL;
}

void     print(deque_t *deque)
{
	node_t* aux = deque->front;
	if(empty(deque)) return;
	else
	{
		while(aux != NULL)
		{
		printf("%d ", aux->value);
		aux = aux->next;
		}
		printf("\n");
	}
}
