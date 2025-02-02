#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> um = {{"Alice", 30}, {"Bob", 25}};
    um["Charlie"] = 35;
    std::cout << "Unordered Map elements: ";
    for (const auto& pair : um) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
    return 0;
} 