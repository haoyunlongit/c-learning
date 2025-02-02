/*
 * 文件名: deque_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的双端队列（std::deque）的用法。
 *
 * 特性:
 * - 双端队列（deque）是一种序列容器，支持在两端进行高效的插入和删除操作。
 * - 与 std::vector 类似，deque 也提供了随机访问能力。
 * - 由于其分段存储结构，deque 在中间插入和删除元素的性能优于 vector。
 * - deque 的内存不是连续的，但它提供了与 vector 类似的接口。
 *
 * 性能:
 * - 在两端插入和删除元素的时间复杂度为 O(1)。
 * - 随机访问元素的时间复杂度为 O(1)。
 * - 在中间插入和删除元素的时间复杂度为 O(n)。
 *
 */

#include <iostream>
#include <deque>

int main() {
    //  构造方式:
    // 1. 默认构造: std::deque<int> deq;
    // 2. 初始化列表构造: std::deque<int> deq = {1, 2, 3, 4, 5};
    // 3. 指定大小和初始值: std::deque<int> deq(5, 10); // 创建一个包含5个元素，每个元素值为10的deque
    // 4. 复制构造: std::deque<int> deq2(deq); // 复制构造
    // 5. 范围构造: std::deque<int> deq(vec.begin(), vec.end()); // 使用其他容器的迭代器范围构造
    std::deque<int> deq = {1, 2, 3, 4, 5};

    // 在队列前面插入元素
    deq.push_front(0); // 现在队列为 {0, 1, 2, 3, 4, 5}

    // 在队列后面插入元素
    deq.push_back(6); // 现在队列为 {0, 1, 2, 3, 4, 5, 6}

    // 从队列前面移除元素
    deq.pop_front(); // 现在队列为 {1, 2, 3, 4, 5, 6}

    // 从队列后面移除元素
    deq.pop_back(); // 现在队列为 {1, 2, 3, 4, 5}

    // 访问队列的第一个元素
    std::cout << "Front element: " << deq.front() << std::endl; // 输出 1

    // 访问队列的最后一个元素
    std::cout << "Back element: " << deq.back() << std::endl; // 输出 5

    // 使用 at() 方法访问元素
    try {
        std::cout << "Element at index 2 using at(): " << deq[2] << std::endl; // 输出 30
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range: " << e.what() << std::endl;
    }

    // 访问特定位置的元素
    std::cout << "Element at index 2: " << deq.at(2) << std::endl; // 输出 3

    // 使用迭代器遍历队列
    std::cout << "Deque elements: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 检查队列是否为空
    if (deq.empty()) {
        std::cout << "Deque is empty." << std::endl;
    } else {
        std::cout << "Deque is not empty." << std::endl;
    }

    // 获取队列的大小
    std::cout << "Deque size: " << deq.size() << std::endl; // 输出 5

    return 0;
} 