/*
 * 文件名: class_and_object_example.cpp
 * 描述: 该文件演示了 C++ 中类和对象的基本概念。
 * 
 * 特性:
 * - 类的定义和对象的创建。
 * - 成员变量和成员函数的使用。
 * - 构造函数的初始化列表。
 */

#include <iostream>
#include <string>

class Car {
public:
    // 构造函数
    Car(const std::string& brand, int year) : brand(brand), year(year) {}

    // 成员函数
    void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    // 设置和获取品牌
    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }

    // 设置和获取年份

    std::string getBrand() const {
        return brand;
    }

    int getYear() const {
        return year;
    }

private:
    std::string brand;
    int year;
};

void test(Car& car) {
    std::string brandName = "Toyota";
    car.setBrand(brandName);
}

int main() {
    Car car("3333", 2020);
    test(car);
    car.displayInfo();

    return 0;
} 