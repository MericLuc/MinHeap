#include <minheap.h>

#define INSERTS_NB 20

int main()
{
    int curMin;
    MinHeap<int, int> m(300);

    std::cout << "Capacity : " << m.getCapacity()              << std::endl;
    std::cout << "Size before any insertion : " << m.getSize() << std::endl;

    for (int i = 1; i <= INSERTS_NB; i++) m.insert(i, i);
    std::cout << "Size after " << INSERTS_NB << " insertions : " << m.getSize() << std::endl;

    m.clear();

    std::cout << "Capacity after clear : " << m.getCapacity()  << std::endl;
    std::cout << "Size after clear : "     << m.getSize()      << std::endl;

    for (int i = 0; i <= INSERTS_NB; i++) m.insert(i, i);

    std::cout << "Elements after " << INSERTS_NB << " insertions " << std::endl;
    while ( !m.empty() )
        if ( m.getMin(curMin) ) { std::cout << curMin << std::endl; m.deleteMin(); }

    return 0;
}
