#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> us = {3, 1, 4, 1, 5};
    us.insert(2);
    std::cout << "Unordered Set elements: ";
    for (int i : us) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
} 