/*
 * 文件名: queue_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的队列（std::queue）的用法。
 *
 * 特性:
 * - 队列是一种容器适配器，提供先进先出（FIFO）的数据结构。
 * - 只允许在一端插入元素（尾部）和在另一端移除元素（头部）。
 *
 * 底层实现:
 * - 默认情况下，std::queue 使用 std::deque 作为底层容器。
 */

#include <iostream>
#include <queue>

// 示例 1: 基本队列操作
void basicQueueOperations() {
    std::queue<int> q;

    // 插入元素
    q.push(10);
    q.push(20);
    q.push(30);

    // 访问队列的头部和尾部
    std::cout << "Front element: " << q.front() << std::endl; // 输出 10
    std::cout << "Back element: " << q.back() << std::endl;   // 输出 30

    // 移除头部元素
    q.pop();
    std::cout << "Front element after pop: " << q.front() << std::endl; // 输出 20

    // 检查队列是否为空
    if (q.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // 获取队列的大小
    std::cout << "Queue size: " << q.size() << std::endl; // 输出 2
}

// 示例 2: 使用自定义对象
struct Customer {
    std::string name;
    int serviceTime;

    Customer(const std::string& n, int t) : name(n), serviceTime(t) {}
};

void customObjectQueue() {
    std::queue<Customer> customerQueue;

    // 插入自定义对象
    customerQueue.push(Customer("Alice", 5));
    customerQueue.push(Customer("Bob", 3));
    customerQueue.push(Customer("Charlie", 7));

    // 处理队列中的客户
    while (!customerQueue.empty()) {
        Customer current = customerQueue.front();
        std::cout << "Serving customer: " << current.name << " with service time " << current.serviceTime << std::endl;
        customerQueue.pop();
    }
}

int main() {
    std::cout << "Basic Queue Operations:" << std::endl;
    basicQueueOperations();

    std::cout << "\nCustom Object Queue:" << std::endl;
    customObjectQueue();

    return 0;
} 