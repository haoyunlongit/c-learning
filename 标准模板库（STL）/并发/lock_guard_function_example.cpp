#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedCounter = 0;

void safeIncrement() {
    std::lock_guard<std::mutex> lock(mtx); // 自动锁定
    ++sharedCounter;
    std::cout << "Incremented to " << sharedCounter << std::endl;
    // lock 在函数结束时自动解锁
}

void increment() {
    for (int i = 0; i < 100; ++i) {
        safeIncrement();
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << sharedCounter << std::endl;
    return 0;
} 