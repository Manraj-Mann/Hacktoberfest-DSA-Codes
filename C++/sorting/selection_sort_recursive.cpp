#include <algorithm>  /// for std::is_sorted
#include <cassert>    /// for assert
#include <iostream>   /// for std::swap and io operations
#include <vector>     /// for std::vector

namespace sorting {

namespace selection_sort_recursive {

template <typename T>
uint64_t findMinIndex(const std::vector<T> &in_arr,
                      uint64_t current_position = 0) {
    if (current_position + 1 == in_arr.size()) {
        return current_position;
    }
    uint64_t answer = findMinIndex(in_arr, current_position + 1);
    if (in_arr[current_position] < in_arr[answer]) {
        answer = current_position;
    }
    return answer;
}


template <typename T>
void selectionSortRecursive(std::vector<T> &in_arr,
                            uint64_t current_position = 0) {
    if (current_position == in_arr.size()) {
        return;
    }
    uint64_t min_element_idx =
        selection_sort_recursive::findMinIndex(in_arr, current_position);
    if (min_element_idx != current_position) {
        std::swap(in_arr[min_element_idx], in_arr[current_position]);
    }
    selectionSortRecursive(in_arr, current_position + 1);
}
}  // namespace selection_sort_recursive
}  // namespace sorting


static void test() {
    // 1st test
    // [1, 0, 2, 1] return [0, 1, 1, 2]
    std::vector<uint64_t> array1 = {0, 1, 1, 2};
    std::cout << "1st test... ";
    sorting::selection_sort_recursive::selectionSortRecursive(array1);
    assert(std::is_sorted(std::begin(array1), std::end(array1)));
    std::cout << "passed" << std::endl;
    // 2nd test
    // [1, 0, 0, 1, 1, 0, 2, 1] return [0, 0, 0, 1, 1, 1, 1, 2]
    std::vector<uint64_t> array2 = {1, 0, 0, 1, 1, 0, 2, 1};
    std::cout << "2nd test... ";
    sorting::selection_sort_recursive::selectionSortRecursive(array2);
    assert(std::is_sorted(std::begin(array2), std::end(array2)));
    std::cout << "passed" << std::endl;
    // 3rd test
    // [1, 1, 0, 0, 1, 2, 2, 0, 2, 1] return [0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
    std::vector<uint64_t> array3 = {1, 1, 0, 0, 1, 2, 2, 0, 2, 1};
    std::cout << "3rd test... ";
    sorting::selection_sort_recursive::selectionSortRecursive(array3);
    assert(std::is_sorted(std::begin(array3), std::end(array3)));
    std::cout << "passed" << std::endl;
    // 4th test
    // [2, 2, 2, 0, 0, 1, 1] return [0, 0, 1, 1, 2, 2, 2]
    std::vector<uint64_t> array4 = {2, 2, 2, 0, 0, 1, 1};
    std::cout << "4th test... ";
    sorting::selection_sort_recursive::selectionSortRecursive(array4);
    assert(std::is_sorted(std::begin(array4), std::end(array4)));
    std::cout << "passed" << std::endl;
}

int main() {
    test();  // run self-test implementations
    return 0;
}
