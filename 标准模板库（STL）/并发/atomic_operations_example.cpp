 ///原子操作

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> atomicCounter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::cout << "increment: " << atomicCounter.load() << std::endl;
        ++atomicCounter; // 原子递增
    }
}

void decrement() {
    for (int i = 0; i < 1000; ++i) {
        std::cout << "decrement: " << atomicCounter.load() << std::endl;
        --atomicCounter; // 原子递减
    }
}

void compareExchangeExample() {
    int expected = 0;
    int desired = 100;

    // 尝试将 atomicCounter 从 expected 更改为 desired
    if (atomicCounter.compare_exchange_strong(expected, desired)) {
        std::cout << "Exchange successful: " << atomicCounter.load() << std::endl;
    } else {
        std::cout << "Exchange failed, current value: " << atomicCounter.load() << std::endl;
    }
}

void add() {
    for (int i = 0; i < 1000; ++i) {
        atomicCounter.fetch_add(1); // 原子加法
    }
}

void sub() {
    for (int i = 0; i < 1000; ++i) {
        atomicCounter.fetch_sub(1); // 原子减法
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(decrement);
    t1.join();
    t2.join();
    std::cout << "After increment and decrement: " << atomicCounter.load() << std::endl;

    std::thread t3(compareExchangeExample);
    std::thread t4(compareExchangeExample);
    t3.join();
    t4.join();

    std::thread t5(add);
    std::thread t6(sub);
    t5.join();
    t6.join();
    std::cout << "Final atomic counter value: " << atomicCounter.load() << std::endl;

    return 0;
} 