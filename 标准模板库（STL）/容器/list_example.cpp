/*
 * 文件名: list_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的双向链表（std::list）的用法。
 *
 * 特性:
 * - 双向链表，允许在常数时间内在任意位置插入和删除元素。
 * - 不支持随机访问。
 *
 * 底层实现:
 * - 通常实现为双向链表，每个节点包含指向前后节点的指针。
 */

#include <iostream>
#include <list>

// 示例 1: 基本 list 操作
void basicListOperations() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // 插入元素
    lst.push_back(6);
    lst.push_front(0);

    // 访问第一个和最后一个元素
    std::cout << "Front element: " << lst.front() << std::endl; // 输出 0
    std::cout << "Back element: " << lst.back() << std::endl;   // 输出 6

    // 删除元素
    lst.pop_front();
    lst.pop_back();

    // 遍历 list
    std::cout << "List elements: ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// 示例 2: 使用自定义对象
struct Person {
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}
};

void customObjectList() {
    std::list<Person> people;
    people.emplace_back("Alice", 30);
    people.emplace_back("Bob", 25);
    people.emplace_back("Charlie", 35);

    // 遍历 list 中的自定义对象
    for (const auto& person : people) {
        std::cout << person.name << " is " << person.age << " years old." << std::endl;
    }
}

int main() {
    std::cout << "Basic List Operations:" << std::endl;
    basicListOperations();

    std::cout << "\nCustom Object List:" << std::endl;
    customObjectList();

    return 0;
} 