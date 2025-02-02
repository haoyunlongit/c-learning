#include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "Stack top: " << stk.top() << std::endl;
    stk.pop();
    std::cout << "Stack top after pop: " << stk.top() << std::endl;
    return 0;
} 