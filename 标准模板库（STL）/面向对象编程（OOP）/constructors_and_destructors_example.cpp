/*
 * 文件名: constructors_and_destructors_example.cpp
 * 描述: 该文件演示了 C++ 中构造函数和析构函数的用法。
 * 
 * 特性:
 * - 构造函数的重载。
 * - 析构函数的使用。
 * - 拷贝构造函数和移动构造函数。
 */

#include <iostream>
#include <string>

class Book {
public:
    // 构造函数
    Book(const std::string& title) : title(title) {
        std::cout << "Book created: " << title << std::endl;
    }

    // 拷贝构造函数
    Book(const Book& other) : title(other.title) {
        std::cout << "Book copied: " << title << std::endl;
    }

    // 析构函数
    ~Book() {
        std::cout << "Book destroyed: " << title << std::endl;
    }

private:
    std::string title;
};

int main() {
    Book book1("C++ Primer");
    Book book2 = book1; // 调用拷贝构造函数
    return 0;
} 