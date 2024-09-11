//Name:Pruthvi Nandan Janga
//ID:1225338491
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// Function to initialize a heap with a given capacity
HEAP *initHeap(int capacity)
{
    HEAP *heap = new HEAP;  // Allocate memory for the heap structure
    if (!heap)
    {
        return nullptr;  // Return nullptr if memory allocation fails
    }
    heap->capacity = capacity;  // Set the capacity of the heap
    heap->size = 0;  // Initialize the size of the heap to zero
    heap->H = new ELEMENT *[capacity];  // Allocate memory for the array of elements
    if (!heap->H)
    {
        delete heap;  // Clean up if memory allocation for the array fails
        return nullptr;
    }
    return heap;  // Return the initialized heap
}

// Function to print the elements of the heap
void printHeap(const HEAP *heap)
{
    if (!heap)
    {
        std::cerr << "Error: heap is NULL" << std::endl;
        return;
    }
    std::cout << heap->size << std::endl;  // Print the size of the heap
    for (int i = 0; i < heap->size; ++i)
    {
        std::cout << std::fixed << std::setprecision(6) << heap->H[i]->key << std::endl;  // Print each element's key
    }
}

// Function to write the elements of the heap to a file
void writeHeap(const HEAP *heap, const std::string &outputFile)
{
    if (!heap)
    {
        std::cerr << "Error: heap is NULL" << std::endl;
        return;
    }
    std::ofstream ofs(outputFile);  // Open the output file
    if (!ofs)
    {
        std::cerr << "Error: cannot open file " << outputFile << std::endl;
        return;
    }
    ofs << heap->size << std::endl;  // Write the size of the heap to the file
    for (int i = 0; i < heap->size; ++i)
    {
        ofs << std::fixed << std::setprecision(6) << heap->H[i]->key << std::endl;  // Write each element's key to the file
    }
    ofs.close();  // Close the output file
}

// Function to read the elements of the heap from a file
void readHeap(HEAP *heap, const std::string &inputFile, int flag)
{
    if (!heap)
    {
        std::cerr << "Error: heap is NULL" << std::endl;
        return;
    }

    std::ifstream ifs(inputFile);  // Open the input file
    if (!ifs)
    {
        std::cerr << "Error: cannot open file " << inputFile << std::endl;
        return;
    }

    int n;
    ifs >> n;  // Read the number of elements from the file
    if (heap->capacity < n)
    {
        std::cerr << "Error: heap capacity is smaller than the number of elements" << std::endl;
        ifs.close();
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        double key;
        ifs >> key;  // Read each element's key from the file
        ELEMENT *elem = new ELEMENT;
        elem->key = key;
        heap->H[i] = elem;
    }
    heap->size = n;  // Set the size of the heap

    ifs.close();  // Close the input file

    // Check if the heap is a min-heap
    if (!isMinHeap(heap))
    {
        if (flag == 2 || flag == 3)
        {
            std::cout << "Input array is NOT a MinHeap" << std::endl;
            std::cout << "Call BuildHeap" << std::endl;
        }
        int heapifyCount = buildHeap(heap);  // Build the heap if it's not a min-heap
        if (flag == 2 || flag == 3)
        {
            std::cout << "Number of Heapify calls triggered by BuildHeap: " << heapifyCount << std::endl;
        }
    }
}

// Function to insert an element into the heap
void insertHeap(HEAP *heap, double key, int flag)
{
    if (heap->size >= heap->capacity)
    {
        std::cerr << "Error: heap is full" << std::endl;
        return;
    }

    ELEMENT *elem = new ELEMENT;  // Create a new element
    elem->key = key;
    heap->H[heap->size] = elem;  // Insert the new element at the end of the heap
    heap->size++;

    // Bubble up to maintain the min-heap property
    int i = heap->size - 1;
    while (i != 0 && heap->H[(i - 1) / 2]->key > heap->H[i]->key)
    {
        double temp = heap->H[i]->key;
        heap->H[i]->key = heap->H[(i - 1) / 2]->key;
        heap->H[(i - 1) / 2]->key = temp;
        i = (i - 1) / 2;
    }

    // Print the insertion details based on the flag
    if (flag == 1 || flag == 3)
    {
        std::cout << "Element with key " << std::fixed << std::setprecision(6) << key << " inserted at location " << i + 1 << " of the heap array" << std::endl;
    }
    else
    {
        std::cout << "Element with key " << std::fixed << std::setprecision(6) << key << " inserted into the heap" << std::endl;
    }
}

// Function to extract the minimum element from the heap
void extractMin(HEAP *heap, int flag)
{
    if (heap->size == 0)
    {
        std::cerr << "Error: heap is empty" << std::endl;
        return;
    }

    double minKey = heap->H[0]->key;  // Store the minimum key
    delete heap->H[0];  // Delete the minimum element
    heap->H[0] = heap->H[heap->size - 1];  // Move the last element to the root
    heap->size--;

    int heapifyCount = 0;
    heapify(heap, 0, heapifyCount);  // Heapify to maintain the min-heap property

    // Print the extraction details based on the flag
    if (flag == 2 || flag == 3)
    {
        std::cout << "Element with key " << std::fixed << std::setprecision(6) << minKey << " extracted from the heap" << std::endl;
        std::cout << "Number of Heapify calls triggered by ExtractMin: " << heapifyCount << std::endl;
    }
    else
    {
        std::cout << "Element with key " << std::fixed << std::setprecision(6) << minKey << " extracted from the heap" << std::endl;
    }
}

// Function to decrease the key of an element at a given position
void decreaseKey(HEAP *heap, int position, double newKey)
{
    if (newKey >= heap->H[position]->key)
    {
        std::cerr << "Error: invalid call to DecreaseKey" << std::endl;
        return;
    }
    heap->H[position]->key = newKey;
    // Bubble up to maintain the min-heap property
    while (position > 0 && heap->H[(position - 1) / 2]->key > heap->H[position]->key)
    {
        double temp = heap->H[position]->key;
        heap->H[position]->key = heap->H[(position - 1) / 2]->key;
        heap->H[(position - 1) / 2]->key = temp;
        position = (position - 1) / 2;
    }
}

// Function to delete the heap and free the allocated memory
void deleteHeap(HEAP *heap)
{
    if (heap)
    {
        for (int i = 0; i < heap->size; ++i)
        {
            delete heap->H[i];  // Delete each element in the heap
        }
        delete[] heap->H;  // Delete the array of elements
        delete heap;  // Delete the heap structure
    }
}
