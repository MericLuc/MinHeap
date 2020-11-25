# MinHeap
A templated implementation of a MinHeap structure built on a dynamic array

This implementation uses 2 templated-types
  - KeyType : A type to keep the items in order
  - ValType : A type for the actual value of the items
  
Supported operations
  - MinHeap::insert to insert a new <key, value> pair in the Heap
  - MinHeap::getMin to retrieve the minimal value of the Heap
  - MinHeap::deleteMin to remove the minimal value from the Heap
  - MinHeap::empty
  - MinHeap::getSize to retrieve the current number of items in the Heap
  - MinHeap::getCapacity to retrieve the maximal number of items the Heap can store
  - MinHeap::clear to remove every item from the Heap.

NB : The root of the heap is the element of the dynamic array at index 1 (not 0)
It allows for faster computations of fathers/sons nodes using bitwise arithmetic.
Please see https://stackoverflow.com/questions/22900388/why-in-a-heap-implemented-by-array-the-index-0-is-left-unused for more details.
