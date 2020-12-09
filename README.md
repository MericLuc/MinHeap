# MinHeap ![Language](https://img.shields.io/badge/language-C++11-orange.svg) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)
A templated implementation of a MinHeap structure built on a dynamic array

This implementation uses 2 templated-types
  - KeyType : A type to keep the items in order
  - ValType : A type for the actual value of the items
  
Supported operations
  - _MinHeap::insert()_ to insert a new <key, value> pair in the Heap
  - _MinHeap::getMin()_ to retrieve the minimal value of the Heap
  - _MinHeap::deleteMin()_ to remove the minimal value from the Heap
  - _MinHeap::empty_()
  - _MinHeap::getSize()_ to retrieve the current number of items in the Heap
  - _MinHeap::getCapacity()_ to retrieve the maximal number of items the Heap can store
  - _MinHeap::clear()_ to remove every item from the Heap.

NB : The root of the heap is the element of the dynamic array at index 1 (not 0)
It allows for faster computations of fathers/sons nodes using bitwise arithmetic.
Please see https://stackoverflow.com/questions/22900388/why-in-a-heap-implemented-by-array-the-index-0-is-left-unused for more details.
