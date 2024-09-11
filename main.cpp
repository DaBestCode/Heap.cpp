//Name:Pruthvi Nandan Janga
//ID:1225338491
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "data_structures.h"
#include "util.h"
#include "heap.h"
#include "main.h"

// Function to print usage instructions for the program
void printUsage()
{
    std::cerr << "Usage: ./PJ2 flag <FileI> <FileO>\n"
              << "flag is in {0, 1, 2, 3}\n"
              << "<FileI> is the input file\n"
              << "<FileO> is the output file\n";
}

// Main function to handle heap operations based on user input
int main(int argc, char *argv[])
{
    // Validate the number of command line arguments
    if (argc != 4)
    {
        printUsage();
        return 1;
    }

    // Parse command line arguments
    int flag = std::stoi(argv[1]);
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    // Validate the flag value
    if (flag < 0 || flag > 3)
    {
        printUsage();
        return 1;
    }

    // Initialize heap pointer
    HEAP *heap = nullptr;
    std::string command;

    // Process each command read from standard input
    while (std::getline(std::cin, command))
    {
        std::istringstream iss(command);
        std::string instruction;
        iss >> instruction;

        // Handle "Stop" instruction to terminate the program
        if (instruction == "Stop")
        {
            std::cout << "Instruction: Stop" << std::endl;
            break;
        }
        // Handle "Init" instruction to initialize a heap with specified capacity
        else if (instruction == "Init")
        {
            int capacity;
            iss >> capacity;
            std::cout << "Instruction: Init " << capacity << std::endl;
            heap = initHeap(capacity);
            if (!heap)
            {
                std::cerr << "Error: memory allocation failed" << std::endl;
                return 1;
            }
        }
        // Handle "Print" instruction to print the current state of the heap
        else if (instruction == "Print")
        {
            std::cout << "Instruction: Print" << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else
            {
                printHeap(heap);
            }
        }
        // Handle "Write" instruction to write the heap to an output file
        else if (instruction == "Write")
        {
            std::cout << "Instruction: Write" << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else
            {
                writeHeap(heap, outputFile);
            }
        }
        // Handle "Read" instruction to read the heap from an input file
        else if (instruction == "Read")
        {
            std::cout << "Instruction: Read" << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else
            {
                readHeap(heap, inputFile, flag);
            }
        }
        // Handle "Insert" instruction to insert a new key into the heap
        else if (instruction == "Insert")
        {
            double key;
            iss >> key;
            std::cout << "Instruction: Insert " << std::fixed << std::setprecision(6) << key << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else if (heap->size >= heap->capacity)
            {
                std::cerr << "Error: heap is full" << std::endl;
            }
            else
            {
                insertHeap(heap, key, flag);
            }
        }
        // Handle "ExtractMin" instruction to extract the minimum key from the heap
        else if (instruction == "ExtractMin")
        {
            std::cout << "Instruction: ExtractMin" << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else if (heap->size == 0)
            {
                std::cerr << "Error: heap is empty" << std::endl;
            }
            else
            {
                extractMin(heap, flag);
            }
        }
        // Handle "DecreaseKey" instruction to decrease the key of an element at a given position
        else if (instruction == "DecreaseKey")
        {
            int position;
            double newKey;
            iss >> position >> newKey;
            std::cout << "Instruction: DecreaseKey " << position << " " << std::fixed << std::setprecision(6) << newKey << std::endl;
            if (!heap)
            {
                std::cerr << "Error: heap is NULL" << std::endl;
            }
            else if (heap->size == 0)
            {
                std::cerr << "Error: heap is empty" << std::endl;
            }
            else if (position - 1 < 0 || position - 1 >= heap->size || newKey >= heap->H[position - 1]->key)
            {
                std::cerr << "Error: invalid call to DecreaseKey" << std::endl;
            }
            else
            {
                decreaseKey(heap, position - 1, newKey);
            }
        }
        // Handle invalid instructions
        else
        {
            std::cout << "Warning: Invalid instruction" << std::endl;
        }
    }

    // Clean up and delete the heap
    deleteHeap(heap);
    return 0;
}
