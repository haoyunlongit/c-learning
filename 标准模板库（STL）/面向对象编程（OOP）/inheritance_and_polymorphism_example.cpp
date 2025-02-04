/*
 * 文件名: inheritance_and_polymorphism_example.cpp
 * 描述: 该文件演示了 C++ 中的继承和多态性。
 * 
 * 特性:
 * - 单继承和多态性。
 * - 虚函数和纯虚函数。
 * - 动态多态性和基类指针。
 */

#include <iostream>
#include <string>

// 基类
class Animal {
public:
    // 纯虚函数
    virtual void speak() const = 0;
    virtual ~Animal() {}
};

// 派生类
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animals[] = {new Dog(), new Cat()};
    for (Animal* animal : animals) {
        animal->speak();
        delete animal;
    }
    return 0;
} 