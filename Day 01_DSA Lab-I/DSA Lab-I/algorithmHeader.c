//The <algorithm> header file
//provides a collection of functions for performing various algorithms on containers like vectors, arrays, and lists
//needed for algorithms like sorting, searching, or manipulating elements in containers.

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {4, 2, 7, 5, 1, 3};

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    std::cout << "Sorted numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
