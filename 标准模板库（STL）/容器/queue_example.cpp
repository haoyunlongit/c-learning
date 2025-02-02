#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Queue front: " << q.front() << std::endl;
    q.pop();
    std::cout << "Queue front after pop: " << q.front() << std::endl;
    return 0;
} 