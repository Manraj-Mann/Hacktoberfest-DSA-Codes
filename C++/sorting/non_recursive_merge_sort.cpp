
#include <cstddef>  // for size_t
#include <iostream>
#include <utility>  // for std::move & std::remove_reference_t

namespace sorting {
template <class Iterator>
void merge(Iterator, Iterator, const Iterator, char[]);

template <class Iterator>
void non_recursive_merge_sort(const Iterator first, const Iterator last,
                              const size_t n) {
    // create a buffer large enough to store all elements
    // dynamically allocated to comply with cpplint
    char* buffer = new char[n * sizeof(*first)];
      for (size_t length(1); length < n; length <<= 1) {
        // merge adjacent segments whose number is n / (length * 2)
        Iterator left(first);
        for (size_t counter(n / (length << 1)); counter; --counter) {
            Iterator right(left + length), end(right + length);
            merge(left, right, end, buffer);
            left = end;
        }

        if ((n & ((length << 1) - 1)) > length)
            merge(left, left + length, last, buffer);
    }
    delete[] buffer;
}

template <class Iterator>
void merge(Iterator l, Iterator r, const Iterator e, char b[]) {
    // create 2 pointers to point at the buffer
    auto p(reinterpret_cast<std::remove_reference_t<decltype(*l)>*>(b)), c(p);
    // move the left part of the segment
    for (Iterator t(l); r != t; ++t) *p++ = std::move(*t);
    // while neither the buffer nor the right part has been exhausted
    // move the smallest element of the two back to the container
    while (e != r && c != p) *l++ = std::move(*r < *c ? *r++ : *c++);
    // notice only one of the two following loops will be executed
    // while the right part hasn't bee exhausted, move it back
    while (e != r) *l++ = std::move(*r++);
    // while the buffer hasn't bee exhausted, move it back
    while (c != p) *l++ = std::move(*c++);
}
/// bottom-up merge sort which sorts elements in a non-decreasing order
/**
 * @param first points to the first element
 * @param n the number of elements
 */
template <class Iterator>
void non_recursive_merge_sort(const Iterator first, const size_t n) {
    non_recursive_merge_sort(first, first + n, n);
}
/// bottom-up merge sort which sorts elements in a non-decreasing order
/**
 * @param first points to the first element
 * @param last points to 1-step past the last element
 */
template <class Iterator>
void non_recursive_merge_sort(const Iterator first, const Iterator last) {
    non_recursive_merge_sort(first, last, last - first);
}

}  // namespace sorting

using sorting::non_recursive_merge_sort;

int main(int argc, char** argv) {
    int size;
    std::cout << "Enter the number of elements : ";
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    non_recursive_merge_sort(arr, size);
    std::cout << "Sorted array\n";
    for (int i = 0; i < size; ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << '\n';
    delete[] arr;
    return 0;
}
