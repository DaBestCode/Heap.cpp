//Name:Pruthvi Nandan Janga
//ID:1225338491
#include "heap.h"
#include <iostream>
#include <algorithm>

// Basic heapify function to maintain the min-heap property
int heapify(HEAP *heap, int i, int &heapifyCount)
{
    heapifyCount++; // Increment the count of heapify calls

    int left = 2 * i + 1;  // Index of the left child
    int right = 2 * i + 2; // Index of the right child
    int smallest = i;      // Assume the current node is the smallest

    // Compare the current node with its left child
    if (left < heap->size && heap->H[left]->key < heap->H[smallest]->key)
    {
        smallest = left; // Update the smallest if the left child is smaller
    }

    // Compare the current node with its right child
    if (right < heap->size && heap->H[right]->key < heap->H[smallest]->key)
    {
        smallest = right; // Update the smallest if the right child is smaller
    }

    // If the smallest is not the current node, swap and heapify the affected subtree
    if (smallest != i)
    {
        std::swap(heap->H[i], heap->H[smallest]); // Swap the current node with the smallest child
        heapify(heap, smallest, heapifyCount);    // Recursively heapify the affected subtree
    }

    return heapifyCount; // Return the total number of heapify calls
}

// Function to build a min-heap from an unsorted array
int buildHeap(HEAP *heap)
{
    int heapifyCount = 0;

    // Start from the last non-leaf node and move up to the root
    for (int i = (heap->size - 2) / 2; i >= 0; --i)
    {
        heapify(heap, i, heapifyCount); // Call heapify on each node
    }

    return heapifyCount; // Return the total number of heapify calls
}

// Function to check if the heap is a min-heap
bool isMinHeap(const HEAP *heap)
{
    // Iterate over all non-leaf nodes
    for (int i = 0; i <= (heap->size - 2) / 2; ++i)
    {
        // Check if the current node is greater than its left child
        if (heap->H[i]->key > heap->H[2 * i + 1]->key)
        {
            return false; // Return false if the heap property is violated
        }
        // Check if the current node is greater than its right child (if it exists)
        if (2 * i + 2 < heap->size && heap->H[i]->key > heap->H[2 * i + 2]->key)
        {
            return false; // Return false if the heap property is violated
        }
    }
    return true; // Return true if the heap satisfies the min-heap property
}
