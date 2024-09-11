#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

int heapify(HEAP *heap, int i, int &heapifyCount);
int buildHeap(HEAP *heap);
bool isMinHeap(const HEAP *heap);

#endif // HEAP_H
