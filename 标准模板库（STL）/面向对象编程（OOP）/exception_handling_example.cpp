/*
 * 文件名: exception_handling_example.cpp
 * 描述: 该文件演示了 C++ 中异常处理的用法。
 * 
 * 特性:
 * - 异常的抛出与捕获。
 * - 自定义异常类。
 */

#include <iostream>
#include <stdexcept>

// 自定义异常类
class DivisionByZeroException : public std::runtime_error {
public:
    DivisionByZeroException() : std::runtime_error("Division by zero") {}
};

void divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const DivisionByZeroException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
} 