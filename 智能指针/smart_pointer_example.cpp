/*
 * 文件名: smart_pointer_example.cpp
 * 描述: 该文件演示了 C++ 中使用智能指针进行内存管理。
 * 
 * 特性:
 * - 使用 std::shared_ptr 和 std::unique_ptr 管理动态内存。
 * - 展示智能指针的基本用法。
 */

#include <iostream>
#include <memory>

class MyClass {
private:
    int x = 0;

public:
    MyClass() { }

    MyClass(int x) {
        this->x = x;
        std::cout << "MyClass Constructor with parameter" << std::endl;
    }

    ~MyClass() { std::cout << "MyClass Destructor" << std::endl; }

    void setX(int x) { this->x = x; }

    int getX() { std::cout << "x = " << x << std::endl;
        return x; }

    void display() { std::cout << "Displaying MyClass" << std::endl; }
};

void useSharedPtr() {
    // 创建一个 shared_ptr 实例，指向 MyClass 对象
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr3 = std::make_shared<MyClass>(10);
    std::cout << "Shared Pointer ptr3: " << ptr3->getX() << std::endl;
    {
        // 创建另一个 shared_ptr 实例，指向相同的 MyClass 对象
        std::shared_ptr<MyClass> ptr2 = ptr1;
        ptr2->display();
        std::cout << "Shared Pointer Count: " << ptr1.use_count() << std::endl;
        std::cout << "Shared Pointer Count: p2" << ptr2.use_count() << std::endl; // 输出引用计数
    }
    // 离开内层作用域后，ptr2 被销毁，引用计数减少
    std::cout << "Shared Pointer Count after inner scope: " << ptr1.use_count() << std::endl;
}

void useUniquePtr() {
    // 手动创建 unique_ptr (C++11)
    std::unique_ptr<MyClass> ptr(new MyClass());
    std::unique_ptr<MyClass> ptr2 = std::move(ptr);
    ptr2->display();
    ptr.reset();
    /// 判断ptr是否可用
    if (ptr) {
        std::cout << "ptr is valid" << std::endl;
    } else {
        std::cout << "ptr is invalid" << std::endl;
    }

    if (ptr2) {
        std::cout << "ptr2 is valid" << std::endl;
    } else {
        std::cout << "ptr2 is invalid" << std::endl;
    }
    
    
    
    // std::unique_ptr<MyClass> ptr2 = ptr; // 这行代码会导致编译错误，因为 unique_ptr 不能被复制
}


/// 解释一下 weak_ptr 的用法
/// 1. weak_ptr 是一个弱引用，它不会增加 shared_ptr 的引用计数。
/// 2. 当 shared_ptr 被销毁时，weak_ptr 会自动变为无效。
/// 3. 当需要访问 shared_ptr 指向的对象时，可以使用 lock() 方法获取一个 shared_ptr。
void useWeakPtr() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    std::cout << "Shared Pointer Count: " << sharedPtr.use_count() << std::endl; // 输出引用计数

    // 使用 lock() 方法获取一个 std::shared_ptr
    if (auto tempPtr = weakPtr.lock()) {
        tempPtr->display();
        std::cout << "Weak Pointer is valid." << std::endl;
    } else {
        std::cout << "Weak Pointer is expired." << std::endl;
    }

    sharedPtr.reset(); // 释放 shared_ptr

    // 再次使用 lock() 方法获取一个 std::shared_ptr
    if (auto tempPtr = weakPtr.lock()) {
        std::cout << "Weak Pointer is valid." << std::endl;
    } else {
        std::cout << "Weak Pointer is expired." << std::endl;
    }
}

int main() {
    // std::cout << "Using shared_ptr:" << std::endl;
    // useSharedPtr();

    useUniquePtr();

    // std::cout << "\nUsing weak_ptr:" << std::endl;
    // useWeakPtr();

    return 0;
}
