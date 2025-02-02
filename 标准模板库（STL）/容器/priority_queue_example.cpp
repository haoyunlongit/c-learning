#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    std::cout << "Priority Queue top: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "Priority Queue top after pop: " << pq.top() << std::endl;
    return 0;
} 