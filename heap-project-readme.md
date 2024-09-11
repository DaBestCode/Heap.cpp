# Min-Heap Implementation in C++

This project implements a min-heap data structure in C++ with various operations and a command-line interface for interacting with the heap.

## Project Structure

- `data_structures.h`: Defines the basic structures for the heap implementation.
- `heap.h` and `heap.cpp`: Contain the core heap operations (heapify, build heap, etc.).
- `main.h` and `main.cpp`: Implement the command-line interface and main program logic.
- `util.h`: (Not provided in the given files, but referenced) Likely contains utility functions.

## Features

- Min-heap implementation
- Heap initialization
- Insert elements
- Extract minimum element
- Decrease key operation
- Build heap from an array
- Read/Write heap from/to file
- Command-line interface for heap operations

## Usage

Compile the program and run it with the following command-line arguments:

```
./PJ2 <flag> <FileI> <FileO>
```

Where:
- `<flag>` is an integer in {0, 1, 2, 3} (determines the behavior of certain operations)
- `<FileI>` is the input file
- `<FileO>` is the output file

## Commands

The program accepts the following commands via standard input:

- `Init <capacity>`: Initialize a heap with the given capacity
- `Print`: Print the current state of the heap
- `Write`: Write the heap to the output file
- `Read`: Read the heap from the input file
- `Insert <key>`: Insert a new key into the heap
- `ExtractMin`: Extract the minimum key from the heap
- `DecreaseKey <position> <newKey>`: Decrease the key at the given position
- `Stop`: Terminate the program

## Author

Pruthvi Nandan Janga

## License

[Include your chosen license here]

## Contributing

[Include guidelines for contributing to your project, if applicable]

## Contact

[Your contact information or preferred method of contact]
