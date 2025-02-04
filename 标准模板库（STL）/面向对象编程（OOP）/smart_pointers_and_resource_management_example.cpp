/*
 * 文件名: smart_pointers_and_resource_management_example.cpp
 * 描述: 该文件演示了 C++ 中智能指针和资源管理的用法。
 * 
 * 特性:
 * - std::unique_ptr, std::shared_ptr, std::weak_ptr 的使用。
 * - 资源的自动管理。
 */

#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released" << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<Resource> res1 = std::make_unique<Resource>();
    } // res1 goes out of scope here

    std::shared_ptr<Resource> res2 = std::make_shared<Resource>();
    std::shared_ptr<Resource> res3 = res2; // res2 and res3 share ownership

    std::weak_ptr<Resource> weakRes = res2; // weak pointer does not affect ownership

    return 0;
} 