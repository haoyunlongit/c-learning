/*
 * 文件名: oop_example.cpp
 * 描述: 该文件演示了 C++ 中的类的继承、接口、多继承、虚函数、纯虚函数和构造方法等概念。
 */

#include <iostream>
#include <string>

// 基类（接口）
class Animal {
public:
    // 纯虚函数，定义接口
    virtual void speak() const = 0;

    // 虚析构函数，确保正确析构派生类对象
    virtual ~Animal() {}
};

// 派生类
class Dog : public Animal {
public:
    Dog(const std::string& name) : name(name) {}

    // 实现基类的纯虚函数
    void speak() const override {
        std::cout << name << " says: Woof!" << std::endl;
    }

private:
    std::string name;
};

// 另一个派生类
class Cat : public Animal {
public:
    Cat(const std::string& name) : name(name) {}

    // 实现基类的纯虚函数
    void speak() const override {
        std::cout << name << " says: Meow!" << std::endl;
    }

private:
    std::string name;
};

// 多继承示例
class Robot {
public:
    void charge() const {
        std::cout << "Charging..." << std::endl;
    }
};

class RoboDog : public Dog, public Robot {
public:
    RoboDog(const std::string& name) : Dog(name) {}

    // 可以选择重写 Dog 的 speak 方法
    void speak() const override {
        std::cout << "RoboDog says: Beep Woof!" << std::endl;
    }
};

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");
    RoboDog roboDog("RoboBuddy");

    // 使用基类指针调用派生类方法
    Animal* animals[] = {&dog, &cat, &roboDog};
    for (Animal* animal : animals) {
        animal->speak();
    }

    // 调用 RoboDog 的特定方法
    roboDog.charge();

    return 0;
} 