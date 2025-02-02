/*
 * 文件名: priority_queue_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的优先级队列（std::priority_queue）的用法。
 *
 * 特性:
 * - 优先级队列是一种容器适配器，提供元素的优先级管理。
 * - 默认情况下，std::priority_queue 是一个最大堆，堆顶元素是优先级最高的元素。
 * - 可以通过自定义比较函数实现最小堆或其他排序规则。
 *
 * 底层实现:
 * - 通常基于 std::vector 实现，并使用堆排序算法来维护元素的顺序。
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// 自定义比较函数，用于实现最小堆
struct MinHeapComparator {
    bool operator()(int left, int right) {
        return left > right; // 反转比较符号以实现最小堆
    }
};

// 示例 1: 使用最大堆
void maxHeapExample() {
    std::priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);

    std::cout << "Max Heap top: " << maxHeap.top() << std::endl; // 输出 4
    maxHeap.pop();
    std::cout << "Max Heap top after pop: " << maxHeap.top() << std::endl; // 输出 3
}

// 示例 2: 使用最小堆
void minHeapExample() {
    std::priority_queue<int, std::vector<int>, MinHeapComparator> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);

    std::cout << "Min Heap top: " << minHeap.top() << std::endl; // 输出 1
    minHeap.pop();
    std::cout << "Min Heap top after pop: " << minHeap.top() << std::endl; // 输出 3
}

// 示例 3: 使用自定义对象
struct Task {
    int priority;
    std::string description;

    // 自定义比较函数，优先级高的任务在堆顶
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

void customObjectExample() {
    std::priority_queue<Task> taskQueue;
    taskQueue.push({2, "Low priority task"});
    taskQueue.push({1, "Medium priority task"});
    taskQueue.push({3, "High priority task"});

    while (!taskQueue.empty()) {
        Task task = taskQueue.top();
        std::cout << "Task: " << task.description << " with priority " << task.priority << std::endl;
        taskQueue.pop();
    }
}

int main() {
    std::cout << "Max Heap Example:" << std::endl;
    maxHeapExample();

    std::cout << "\nMin Heap Example:" << std::endl;
    minHeapExample();

    std::cout << "\nCustom Object Example:" << std::endl;
    customObjectExample();

    return 0;
} 