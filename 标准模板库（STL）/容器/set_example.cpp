/*
 * 文件名: set_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的集合（std::set）的用法。
 *
 * 特性:
 * - 集合是一个关联容器，存储唯一的元素，并根据键自动排序。
 * - 提供高效的插入、删除和查找操作。
 *
 * 底层实现:
 * - 通常使用红黑树（或其他平衡树）实现，保证操作的对数时间复杂度。
 */

#include <iostream>
#include <set>

// 示例 1: 基本 set 操作
void basicSetOperations() {
    std::set<int> s = {3, 1, 4, 1, 5, 9};

    // 插入元素
    s.insert(2);
    s.insert(6);

    // 遍历 set
    std::cout << "Set elements: ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (s.find(3) != s.end()) {
        std::cout << "Element 3 found in set." << std::endl;
    }

    // 删除元素
    s.erase(1);

    // 检查 set 是否为空
    if (s.empty()) {
        std::cout << "Set is empty." << std::endl;
    } else {
        std::cout << "Set is not empty." << std::endl;
    }

    // 获取 set 的大小
    std::cout << "Set size: " << s.size() << std::endl;
}

// 示例 2: 使用自定义比较函数
struct DescendingOrder {
    bool operator()(int lhs, int rhs) const {
        return lhs > rhs; // 实现降序排序
    }
};

void customComparatorSet() {
    std::set<int, DescendingOrder> s = {3, 1, 4, 1, 5, 9};

    // 插入元素
    s.insert(2);
    s.insert(6);

    // 遍历 set
    std::cout << "Set elements in descending order: ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Basic Set Operations:" << std::endl;
    basicSetOperations();

    std::cout << "\nCustom Comparator Set:" << std::endl;
    customComparatorSet();

    return 0;
} 