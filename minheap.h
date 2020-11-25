/*!
 * @file   bst.h
 * @brief  Header for home-made implementation of a Min-Heap class
 *         using dynamic arrays.
 * @author lhm
 * @date   25/11/2020
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include <cstdint>
#include <iostream>
#include <cstring>

#define ASSERT(cond, msg) \
if ( !(cond) ) { \
    std::cerr << "Assertion `" #cond "` failed in " << __FILE__ \
              << " line " << __LINE__ << ": " << msg << std::endl; \
    std::terminate(); \
} \

template <typename KeyType, typename ValType>
class MinHeap
{
    struct Item { KeyType k; ValType v; };

private:
    Item      *arr ; /*!< Dynamic array holding the items */
    uint32_t   cap ; /*!< Capacity of the MinHeap         */
    uint32_t   size; /*!< Size of the MinHeap             */

private:
    /*!
     * \brief expand Double the size allowed for the heap container (dynamic array)
     */
    void expand  (void) {
        if ( !arr ) { arr = new Item[2]; cap = 1; size = 0; }
        else {
            cap <<= 1;
            Item *tmp = new Item[cap+1];
            memcpy(tmp, arr, sizeof(Item) * (size+1));

            delete[] arr;
            arr = tmp;
        }
    }

    void siftUp  (uint32_t i) {
        if ( i > 1 ) {
            uint32_t prt(i >> 1);

            if ( arr[i].k < arr[prt].k ) {
               std::swap( arr[i], arr[prt] );
               siftUp(prt);
            }
        }
    }

    void siftDown(uint32_t i) {
        uint32_t minIdx(0), lIdx(i << 1), rIdx((i << 1) + 1);

        if ( lIdx <= size && arr[i].k > arr[lIdx].k                       ) { minIdx = lIdx; }
        if ( rIdx <= size && (arr[(minIdx ? minIdx : i)].k > arr[rIdx].k) ) { minIdx = rIdx; }

        if ( !minIdx ) return;

        std::swap(arr[i], arr[minIdx]);
        siftDown(minIdx);
    }

public:
    MinHeap() : arr(nullptr), cap(0), size(0) {}

    MinHeap(uint32_t p_cap) : cap(p_cap), size(0) {
        ASSERT(p_cap, "MinHeap capacity has to be strictly positive");
        arr = new Item[p_cap+1];
    }

    ~MinHeap() { clear(); }

    /*!
     * \brief insert a new [key, val] pair
     * \param p_k the key to insert
     * \param p_v the value to insert
     */
    void insert(const KeyType& p_k, const ValType& p_v) {
        if ( size == cap ) { expand(); }

        arr[size+1].k = p_k;
        arr[size+1].v = p_v;

        siftUp(size);
        ++size;
    }

    /*!
     * \brief getMin retrieves the min value of the Heap
     * \param val the min value to be retrieved
     * \return true if there is such a value (i.e the heap is not empty), false otherwise
     *
     * /!\ It is your responsability to check the return type to ensure \a val
     *     is not garbage!
     */
    bool getMin(ValType& val) { if( size ) { val = arr[1].v; } return size; }

    /*!
     * \brief deleteMin removes the minimal value of the heap
     */
    void deleteMin(void) {
        if ( size ) {
            std::swap(arr[1], arr[size]);
            size--;
            siftDown(1);
        }
    }

    /*!
     * \brief empty
     * \return true if the heap is empty, false otherwise
     */
    bool     empty       (void) const { return (size == 0); }

    /*!
     * \brief getSize
     * \return the size (number of objects) of the heap
     */
    uint32_t getSize     (void) const { return size; }

    /*!
     * \brief getCapacity
     * \return the capacity (maximal possible objects) of the heap
     */
    uint32_t getCapacity (void) const { return cap; }

    /*!
     * \brief clear Removes every element of the heap
     */
    void clear(void) {
        if ( arr )
        {
            delete[] arr;
            arr  = nullptr;
            cap  = 0;
            size = 0;
        }

    }
};


#endif // MINHEAP_H
