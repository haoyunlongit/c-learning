/*
 * 文件名: templates_and_generic_programming_example.cpp
 * 描述: 该文件演示了 C++ 中模板和泛型编程的用法。
 * 
 * 特性:
 * - 类模板和函数模板。
 * - 模板特化。
 */

#include <iostream>

// 类模板
template <typename T>
class Box {
public:
    Box(T value) : value(value) {}

    T getValue() const {
        return value;
    }

private:
    T value;
};

// 函数模板
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    Box<int> intBox(123);
    Box<std::string> strBox("Hello");

    std::cout << "Int Box: " << intBox.getValue() << std::endl;
    std::cout << "String Box: " << strBox.getValue() << std::endl;

    std::cout << "Add: " << add(3, 4) << std::endl;

    return 0;
} 