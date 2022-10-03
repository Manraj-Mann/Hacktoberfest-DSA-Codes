#include <algorithm>
#include <cassert>
#include <iostream>

template <typename T>
void printArray(T *arr, int sz) {
    for (int i = 0; i < sz; i++) std::cout << arr[i] << "  ";
    std::cout << "\n";
}

template <typename T>
void heapify(T *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


template <typename T>
void heapSort(T *arr, int n) {
    for (int i = n - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void test() {
    std::cout << "Test 1\n";
    int arr[] = {-10, 78, -1, -6, 7, 4, 94, 5, 99, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);  // sz - size of array
    printArray(arr, sz);  // displaying the array before sorting
    heapSort(arr, sz);    // calling heapsort to sort the array
    printArray(arr, sz);  // display array after sorting
    assert(std::is_sorted(arr, arr + sz));
    std::cout << "Test 1 Passed\n========================\n";

    std::cout << "Test 2\n";
    double arr2[] = {4.5, -3.6, 7.6, 0, 12.9};
    sz = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, sz);
    heapSort(arr2, sz);
    printArray(arr2, sz);
    assert(std::is_sorted(arr2, arr2 + sz));
    std::cout << "Test 2 passed\n";
}

/** Main function */
int main() {
    test();
    return 0;
}
