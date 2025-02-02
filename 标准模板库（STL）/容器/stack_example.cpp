/*
 * 文件名: stack_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的栈（std::stack）的用法。
 *
 * 特性:
 * - 栈是一种容器适配器，提供后进先出（LIFO）的数据结构。
 * - 只允许在一端（栈顶）插入和移除元素。
 *
 * 底层实现:
 * - 默认情况下，std::stack 使用 std::deque 作为底层容器。
 */

#include <iostream>
#include <stack>

// 示例 1: 基本 stack 操作
void basicStackOperations() {
    std::stack<int> stk;

    // 插入元素
    stk.push(10);
    stk.push(20);
    stk.push(30);

    // 访问栈顶元素
    std::cout << "Top element: " << stk.top() << std::endl; // 输出 30

    // 移除栈顶元素
    stk.pop();
    std::cout << "Top element after pop: " << stk.top() << std::endl; // 输出 20

    // 检查栈是否为空
    if (stk.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // 获取栈的大小
    std::cout << "Stack size: " << stk.size() << std::endl; // 输出 2
}

// 示例 2: 使用自定义对象
struct Book {
    std::string title;
    int id;

    Book(const std::string& t, int i) : title(t), id(i) {}
};

void customObjectStack() {
    std::stack<Book> bookStack;

    // 插入自定义对象
    bookStack.push(Book("C++ Primer", 1));
    bookStack.push(Book("Effective C++", 2));
    bookStack.push(Book("The C++ Programming Language", 3));

    // 处理栈中的书籍
    while (!bookStack.empty()) {
        Book current = bookStack.top();
        std::cout << "Book: " << current.title << " with ID " << current.id << std::endl;
        bookStack.pop();
    }
}

int main() {
    std::cout << "Basic Stack Operations:" << std::endl;
    basicStackOperations();

    std::cout << "\nCustom Object Stack:" << std::endl;
    customObjectStack();

    return 0;
} 