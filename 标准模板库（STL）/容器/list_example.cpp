#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_front(0);
    lst.push_back(6);
    lst.pop_front();
    std::cout << "List elements: ";
    for (int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
} 