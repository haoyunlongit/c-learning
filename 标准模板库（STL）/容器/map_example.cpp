/*
 * 文件名: map_example.cpp
 * 描述: 该文件演示了 C++ 标准库中的映射（std::map）的用法。
 *
 * 特性:
 * - 映射（map）是一种关联容器，存储键值对，并根据键自动排序。
 * - 键是唯一的，不能重复。
 * - 提供高效的键查找、插入和删除操作。
 * - 元素按照键的顺序存储，默认按升序排序。
 * 性能:
 * - 插入、删除和查找操作的时间复杂度为 O(log n)。
 * - 使用红黑树（或其他平衡树）实现，保证操作的对数时间复杂度。
 *
 * 构造方式:
 * 1. 默认构造: std::map<std::string, int> m;
 * 2. 初始化列表构造: std::map<std::string, int> m = {{"Alice", 30}, {"Bob", 25}};
 * 3. 复制构造: std::map<std::string, int> m2(m); // 复制构造
 * 4. 范围构造: std::map<std::string, int> m(vec.begin(), vec.end()); // 使用其他容器的迭代器范围构造
 */

#include <iostream>
#include <map>

void basicOperations() {
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}};

    // 插入新的键值对
    ageMap["Charlie"] = 35;

    // 访问特定键的值
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

    // 使用 find() 方法查找键
    auto it = ageMap.find("Bob");
    if (it != ageMap.end()) {
        std::cout << "Bob's age: " << it->second << std::endl;
    } else {
        std::cout << "Bob not found." << std::endl;
    }

    // 使用迭代器遍历映射
    std::cout << "Map elements: ";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    // 检查映射是否为空
    if (ageMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    } else {
        std::cout << "Map is not empty." << std::endl;
    }

    // 获取映射的大小
    std::cout << "Map size: " << ageMap.size() << std::endl;
}

// 1 插入元素 
// 如果元素存在，则不插入
// 如果元素不存在，则插入
// 使用 insert 方法批量插 ageMap.insert(newEntries.begin(), newEntries.end());
void insertExample(std::map<std::string, int>& ageMap) {
    auto result = ageMap.insert(std::make_pair("Eve", 28));
    // result是pair类型，first是迭代器，second是布尔值
    // 其中first迭代器指向插入的元素，second是布尔值，表示是否插入成功
    if (!result.second) {
        std::cout << "Alice already exists with age: " << result.first->second << std::endl;
    } else {
        std::cout << "Alice inserted successfully." << " Eve age " << result.first->second << std::endl;
    }

    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << " " << std::endl;
    }
}

// 删除元素
void eraseExample(std::map<std::string, int>& ageMap) {
    ageMap.erase("Bob");
    auto it = ageMap.find("Charlie");
    if (it != ageMap.end()) {
        std::cout << "Charlie found and erased. Charlie age: " << it->second << std::endl;

        ageMap.erase(it);
    }

    std::cout << "Map elements after erase: \n";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
}

// 2 统计元素个数
void countExample(const std::map<std::string, int>& ageMap) {
    //ageMap.count("Alice") > 0 与  ageMap.find("Alice") != ageMap.end() 是等价
    if (ageMap.count("Alice") > 0) {
        std::cout << "Alice is in the map." << "count:" << std::endl;
    } else {
        std::cout << "Alice is not in the map." << std::endl;
    }
}

// 3 获取元素的上下限
void boundsExample(const std::map<std::string, int>& ageMap) {
    //lower_bound 返回一个迭代器，指向第一个不小于给定键的元素
    //upper_bound 返回一个迭代器，指向第一个大于给定键的元素
    auto lb = ageMap.lower_bound("David");
    if (lb != ageMap.end()) {
        std::cout << "Lower bound for 'David': " << lb->first << ": " << lb->second << std::endl;
    }
    auto ub = ageMap.upper_bound("David");
    if (ub != ageMap.end()) {
        std::cout << "Upper bound for 'David': " << ub->first << ": " << ub->second << std::endl;
    }
}

void emplaceExample(std::map<std::string, int>& ageMap) {
    ageMap.emplace("Frank", 45);
    ageMap.emplace("Grace", 32);

    std::cout << "Final map elements: ";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    ageMap.insert(std::make_pair("David", 40));
    ageMap.insert(std::make_pair("Eve", 28));

    // basicOperations();
    // insertExample(ageMap);
    // eraseExample(ageMap);
    // countExample(ageMap);
    // boundsExample(ageMap);
    // emplaceExample(ageMap);
    return 0;
} 