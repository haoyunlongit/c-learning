/*
 * 文件名: vector_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的动态数组（std::vector）的用法。
 *
 * 特性:
 * - 动态数组（vector）是一种序列容器，支持快速的随机访问。
 * - 提供动态调整大小的能力，自动管理内存。
 * - 内存是连续的，适合需要频繁随机访问的场景。
 *
 * 性能:
 * - 随机访问元素的时间复杂度为 O(1)。
 * - 在末尾插入和删除元素的摊销时间复杂度为 O(1)。
 * - 在中间插入和删除元素的时间复杂度为 O(n)。
 *
 * 构造方式:
 * 1. 默认构造: std::vector<int> vec;
 * 2. 初始化列表构造: std::vector<int> vec = {1, 2, 3, 4, 5};
 * 3. 指定大小和初始值: std::vector<int> vec(5, 10); // 创建一个包含5个元素，每个元素值为10的vector
 * 4. 复制构造: std::vector<int> vec2(vec); // 复制构造
 * 5. 范围构造: std::vector<int> vec(arr, arr + 5); // 使用数组指针范围构造
 */

#include <iostream>
#include <vector>

int main() {
    // 创建一个动态数组并初始化
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 在数组末尾插入元素
    vec.push_back(6); // 现在数组为 {1, 2, 3, 4, 5, 6}

    // 从数组末尾移除元素
    vec.pop_back(); // 现在数组为 {1, 2, 3, 4, 5}

    // 访问数组的第一个元素
    std::cout << "First element: " << vec.front() << std::endl; // 输出 1

    // 访问数组的最后一个元素
    std::cout << "Last element: " << vec.back() << std::endl; // 输出 5

    // 访问特定位置的元素
    std::cout << "Element at index 2: " << vec.at(2) << std::endl; // 输出 3

    // 使用迭代器遍历数组
    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 检查数组是否为空
    if (vec.empty()) {
        std::cout << "Vector is empty." << std::endl;
    } else {
        std::cout << "Vector is not empty." << std::endl;
    }

    // 获取数组的大小
    std::cout << "Vector size: " << vec.size() << std::endl; // 输出 5

    // 获取数组的容量
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    return 0;
} 