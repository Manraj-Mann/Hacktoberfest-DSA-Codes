#include <iostream>
#include <list>


namespace sorting {
   
    namespace strand {
        
        template <typename T>
        std::list<T> strand_sort(std::list<T> lst) {
            if (lst.size() < 2) { // Returns list if empty or contains only one element
                return lst; // Returns list
            }
            std::list<T> result; // Define new "result" named list instance.
            std::list<T> sorted; // Define new "sorted" named list instance.
            while(!lst.empty()) /* if lst is not empty */ {
                sorted.push_back(lst.front()); // Adds the first element of "lst" list to the bottom of the "sorted" list.
                lst.pop_front(); // Remove first element of "lst" list.
                for (auto it = lst.begin(); it != lst.end(); ) { // Return the loop as long as the current iterator is not equal to the last literator of the "lst" list.
                    if (sorted.back() <= *it) { // If the last reference of the "sorted" list is less than or equal to the current iterator reference.
                        sorted.push_back(*it); // Adds the iterator retrieved in the loop under the "sorted" list.
                        it = lst.erase(it); // Deletes the element with the current iterator and assigns the deleted element to the iterator.
                    } else {
                        it++; // Next iterator.
                    }
                }
                result.merge(sorted); // Merge "result" list with "sorted" list.
            }
            return result; // Returns sorted list
        }
    }  // namespace strand
}  // namespace sorting


static void test() {
    std::list<int> lst = { -333, 525, 1, 0, 94, 52, 33 };

    std::cout << "Before: ";
    for(auto item: lst) {
        std::cout << item << " ";
    }

    lst = sorting::strand::strand_sort(lst); // Sort list.

    std::cout << "\nAfter: ";
    for(auto item: lst) {
        std::cout << item << " ";
    }
}


int main() {
    test();
    return 0;
}
