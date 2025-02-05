#include <iostream>
#include <thread>
#include <mutex>

class Counter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx); // 自动锁定
        ++value;
        std::cout << "Incremented to " << value << std::endl;
    }

    int getValue() const {
        return value;
    }

private:
    int value = 0;
    mutable std::mutex mtx; // 互斥锁
};

void incrementCounter(Counter& counter) {
    for (int i = 0; i < 100; ++i) {
        counter.increment();
    }
}

int main() {
    Counter counter;
    std::thread t1(incrementCounter, std::ref(counter));
    std::thread t2(incrementCounter, std::ref(counter));

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter.getValue() << std::endl;
    return 0;
} 