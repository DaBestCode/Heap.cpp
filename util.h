#ifndef UTIL_H
#define UTIL_H

#include "data_structures.h"
#include <string>

HEAP* initHeap(int capacity);
void printHeap(const HEAP *heap);
void writeHeap(const HEAP *heap, const std::string &outputFile);
void readHeap(HEAP *heap, const std::string &inputFile, int flag);
void insertHeap(HEAP *heap, double key, int flag);
void extractMin(HEAP *heap, int flag);
void decreaseKey(HEAP *heap, int position, double newKey);
void deleteHeap(HEAP *heap);

#endif // UTIL_H
