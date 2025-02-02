#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};

    // 排序
    std::sort(numbers.begin(), numbers.end());

    // 查找
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    if (it != numbers.end()) {
        std::cout << "Found number: " << *it << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }

    // 打印排序后的结果
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
} 