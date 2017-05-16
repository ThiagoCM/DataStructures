#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct _heap heap_t;

typedef struct _node node_t;

heap_t* create_heap();

void enqueue(heap_t *heap, int item);

int dequeue(heap_t *heap);

int get_parent_index(heap_t* heap, int i);

int get_left_index(heap_t* heap, int i);

int get_right_index(heap_t* heap, int i);

void max_heapify(heap_t* heap, int i);

int item_of(heap_t* heap, int i);

void heapsort(heap_t *heap);

int is_empty(heap_t *heap);

struct _heap{
    heap_t* left;
    heap_t* right;
    heap_t* parent;
    int size;
    int data[MAX_HEAP_SIZE];
};

heap_t* create_heap() {
  heap_t *heap = (heap_t*) malloc(sizeof(heap));
  heap->size = 0;
  heap->left = NULL;
  heap->right = NULL;
  heap->parent = NULL;
  return heap;
}

int is_empty(heap_t *heap) {
  if(heap->size <= 0) {
    return 1;
  } else {
    return 0;
  }
}

int has_left_child(heap_t *heap) {
  if(heap->left != NULL) {
    return 1;
  } else {
    return 0;
  }
}

int has_right_child(heap_t *heap) {
  if(heap->right != NULL) {
    return 1;
  } else {
    return 0;
  }
}

int has_parent(heap_t *heap) {
  if(heap->parent != NULL){
    return 1;
  } else {
    return 0;
  }
}

heap_t get_parent(heap_t *heap) {
  if(has_parent(heap)) {
    return heap->parent;
  } else {
    return NULL;
  }

}

heap_t get_left(heap_t* heap) {
  if(has_left_child(heap)) {
    return heap->right;
  } else {
    return NULL;
  }
}

heap_t get_right(heap_t* heap) {
  if(has_right_child(heap)) {
    return heap->right;
  } else {
    return NULL;
  }

}

int item_of(heap_t *heap, int i) {
  heap_t* current = heap;
  if(i == current->size) {
    return current->data;
  }
  if (has_left_child(current)) {
    item_of(current->left, i);
  }
  if (has_right_child(current)) {
    item_of(current->right, i);
  }
  return -1;
}

void enqueue(heap_t *heap, int item) {
  heap_t *new = create_heap();
  if(previous->size >= MAX_HEAP_SIZE) {
    printf("Heap overflow!\n");
  } else {
    if(heap->size == 0) {
      heap->data = item;
      heap->left = NULL;
      heap->right = NULL;
      heap->parent = NULL;
      heap->size++;
    }else if(!has_left_child(heap)) {
      new->data = item;
      new->right = NULL;
      new->left = NULL;
      new->size = heap->size + 1;
      new->parent = heap;
      heap->left = new;
    }else if(!has_right_child(heap)) {
      new->data = item;
      new->right = NULL;
      new->left = NULL;
      new->size = heap->size + 1;
      new->parent = heap;
      heap->right = new;
    }else if(has_left_child(heap)) {
      enqueue(heap->left, item);
    }else if(has_right_child(heap)) {
      enqueue(heap->right, item);
    }
    node_t parent = get_parent(new);

    while(parent->size >= 1 && new->data > parent->data) {
      new->data = new->data ^ parent->data;
      parent->data = new->data ^ parent->data;
      new->data = parent->data ^ new->data;

      new = parent;

      parent = get_parent(new);
    }
  }

}

int dequeue(heap_t *heap) {
  if(is_empty(heap)) {
    printf("Heap underflow!\n");
    return -1;
  } else {
    int valor;
    heap_t *current = heap;
    heap_t* aux = heap;
    int item = heap->data;
    while(current->right != NULL || current->left != NULL) {
      if(current->left != NULL){
        aux = current->left;
        valor = aux->data;
      }
      if(current->right != NULL) {
        aux = current->right;
        valor = aux->data
      }
      current = current->left;
    }
    
    }
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    max_heapify(heap, 1);
    return item;
  }

}

void max_heapify(heap_t *heap, int i) {
  int largest;
  int left_index = get_left_index(heap, i);
  int right_index = get_right_index(heap, i);

  if(left_index <= heap->size && heap->data[left_index] > heap->data[i]) {
    largest = left_index;
  } else {
    largest = i;
  }

  if(right_index <= heap->size && heap->data[right_index] > heap->data[largest]) {
    largest = right_index;
  }

  if(heap->data[i] != heap->data[largest]) {
    heap->data[i] = heap->data[i] ^ heap->data[largest];
    heap->data[largest] = heap->data[i] ^ heap->data[largest];
    heap->data[i] = heap->data[largest] ^ heap->data[i];
    max_heapify(heap, largest);
  }
}

void heapsort(heap_t *heap) {
  int i;
  for(i = heap->size; i >= 2; i--) {
    heap->data[1] = heap->data[1] ^ heap->data[i];
    heap->data[i] = heap->data[1] ^ heap->data[i];
    heap->data[1] = heap->data[i] ^ heap->data[1];
    heap
  }
}

int main() {
  heap_t *fila = create_heap();


  return 0;
}
