#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct _heap heap_t;

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
    int size;
    int data[MAX_HEAP_SIZE];
};


heap_t* create_heap() {
  heap_t *heap = (heap_t*) malloc(sizeof(heap));
  heap->size = 0;
  heap->data[heap->size] = 0;
  return heap;
}

int is_empty(heap_t *heap) {
  if(heap->size <= 0) {
    return 1;
  } else {
    return 0;
  }
}

int get_parent_index(heap_t *heap, int i) {
  return i/2;
}

int get_left_index(heap_t* heap, int i) {
  return i*2;
}

int get_right_index(heap_t* heap, int i) {
  return ((i * 2) + 1);
}

int item_of(heap_t *heap, int i) {
  return heap->data[i];
}

void enqueue(heap_t *heap, int item) {
  if(heap->size >= MAX_HEAP_SIZE) {
    printf("Heap overflow!\n");
  } else {
    heap->data[++heap->size] = item;

    int key_index = heap->size;
    int parent_index = get_parent_index(heap, heap->size);

    while(parent_index >= 1 && heap->data[key_index] > heap->data[parent_index]) {
      heap->data[key_index] = heap->data[key_index] ^ heap->data[parent_index];
      heap->data[parent_index] = heap->data[key_index] ^ heap->data[parent_index];
      heap->data[key_index] = heap->data[parent_index] ^ heap->data[key_index];

      key_index = parent_index;

      parent_index = get_parent_index(heap, key_index);
    }
  }

}

int dequeue(heap_t *heap) {
  if(is_empty(heap)) {
    printf("Heap underflow!\n");
    return -1;
  } else {
    int item = heap->data[1];
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

    heap->size--;
    max_heapify(heap, 1);
  }
}

int main() {
  heap_t *fila = create_heap();
  enqueue(fila, 10);
  enqueue(fila, 10);
  enqueue(fila, 15);

  return 0;
}
