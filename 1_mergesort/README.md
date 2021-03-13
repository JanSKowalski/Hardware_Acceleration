Mergesort is a recursive sorting algorithm that relies on blocks of sorted elements.

The bitonic mergesort is a parellization of the lowest level comparisisons  
https://en.wikipedia.org/wiki/Bitonic_sorter

2,4 and 8-wise parellization is implemented in the kernel. To change between the three, modify the <code>KERNEL_PRECISION</code> macro in both host.cpp and mergesort.cpp
