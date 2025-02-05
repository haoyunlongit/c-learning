/*
 * 文件名: mutex_example.cpp
 * 描述: 该文件演示了 C++ 中使用 std::mutex 进行线程同步。
 * 
 * 特性:
 * - 使用 std::mutex 保护共享数据。
 * - 展示 lock_guard 和 unique_lock 的用法。
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // 互斥锁
int sharedCounter = 0; // 共享资源
int number = 0;

void increment(int id) {
    for (int i = 0; i < 100; ++i) {
        // 使用 lock_guard 自动管理锁的生命周期
        std::lock_guard<std::mutex> lock(mtx);
        ++sharedCounter;
        // std::cout << "Thread " << id << " incremented counter to " << sharedCounter << std::endl;
    }
}

void decrement(int id) {
    for (int i = 0; i < 100; ++i) {
        // 使用 unique_lock 手动管理锁的生命周期
        std::unique_lock<std::mutex> lock(mtx);
        --sharedCounter;
        
        // std::cout << "Thread " << id << " decremented counter to " << sharedCounter << std::endl;
    }
}

void testPrint(int i) {
    number++;
    std::cout<< "testPrint() i:" << i << "number :" << number <<std::endl;
}

int main() {
    std::vector<std::thread> threads;

    // 创建多个线程进行增减操作
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment, i);
        threads.emplace_back(decrement, i);
        threads.emplace_back(testPrint, i);
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter value: " << sharedCounter << std::endl;
    return 0;
} 