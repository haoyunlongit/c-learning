/*
 * 文件名: operator_overloading_example.cpp
 * 描述: 该文件演示了 C++ 中运算符重载的用法。
 * 
 * 特性:
 * - 常见运算符的重载。
 * - 友元函数的使用。
 */

#include <iostream>

class Complex {
public:
    Complex(double real, double imag) : real(real), imag(imag) {}

    // 重载加法运算符
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

private:
    double real, imag;
};

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    std::cout << "Result: " << c3 << std::endl;
    return 0;
} 