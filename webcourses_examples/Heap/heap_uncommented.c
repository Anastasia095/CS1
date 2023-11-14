#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;

struct Heap {
  int * arr;
  int size;
  int cap;
};

Heap * createHeap();
void swap(Heap * heap, int index1, int index2);
void percolateUp(Heap * heap, int index);
void percolateDown(Heap * heap, int index);
void enqueue(Heap * heap, int value);
void dequeue(Heap * heap);
void front(Heap * heap);
void cleanHeap(Heap * heap);


Heap * createHeap() {
  Heap * res = (Heap *) malloc(sizeof(Heap));
  res->size = 0;
  res->cap = 3;
  res->arr = (int *) malloc(sizeof(int) * res->cap);
  return res;
}
void swap(Heap * heap, int index1, int index2) {
  int temp = heap->arr[index1];
  heap->arr[index1] = heap->arr[index2];
  heap->arr[index2] = temp;
}
void percolateUp(Heap * heap, int index) {
  while (index != 0) {
    int parent = (index - 1) / 2;
    if (heap->arr[index] > heap->arr[parent]) {
      swap(heap, index, parent);
      index = parent;
    } else {
      break;
    }
  }
}
void percolateDown(Heap * heap, int index) {
  while (1) {
    int maxIndex = index;
    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;
    if (leftIndex < heap->size && heap->arr[leftIndex] > heap->arr[maxIndex]) {
      maxIndex = leftIndex;
    }
    if (rightIndex < heap->size && heap->arr[rightIndex] > heap->arr[maxIndex]) {
      maxIndex = rightIndex;
    }
  
    if (maxIndex != index) {
      swap(heap, index, maxIndex);
      index = maxIndex;
    } else {
      break;
    }
  }
}
void enqueue(Heap * heap, int value) {
  if (heap->size == heap->cap) {
    heap->cap *= 2;
    heap->arr = (int *) realloc(heap->arr, sizeof(int) * (heap->cap));
  }
  
  heap->arr[heap->size] = value;
  heap->size++;
  percolateUp(heap, heap->size-1);
}
void dequeue(Heap * heap) {
  if (heap->size == 0) {
    return;
  }
  swap(heap, 0, heap->size - 1);
  heap->size--;
  percolateDown(heap, 0);
}

int getFront(Heap * heap) {
  if (heap->size == 0) {
    return -1;
  }
  return heap->arr[0];
}
void cleanHeap(Heap * heap) {
  free(heap->arr);
  free(heap);
}
void printHeap(Heap * heap) {
  printf("Size: %d\n", heap->size);
  for (int i = 0; i < heap->size; i++) {
    printf("%d ", heap->arr[i]);
    if (i != heap->size - 1) {
      printf(" ");
    } else {
      printf("\n\n");
    }
  }
}

int main(void) {
  Heap * heap = createHeap();
  // Peform some operations
  for (int i = 0; i < 10; i++) {
    // Create a random value to insert
    int value = rand() % 100;

    // Insert it
    printf("Inserting %d...\n", value);
    enqueue(heap, value);

    // Every other loop remove a value from the heap
    if (i % 2) {
      printHeap(heap);
      // Determine the front of the heap
      int fr = getFront(heap);

      // Remove the front value
      printf("Deleting %d...\n", fr);
      dequeue(heap);
    }

    printHeap(heap);
    
  }

  // Clean up the dynamic memory associated with the heap
  cleanHeap(heap);

  // Exit the main function
  return 0;
}