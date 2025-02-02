#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int main() {
    // 示例 1: 使用 vector 的迭代器
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 示例 2: 使用 list 的迭代器
    std::list<std::string> strList = {"Hello", "World", "C++"};
    std::cout << "List elements: ";
    for (std::list<std::string>::iterator it = strList.begin(); it != strList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 示例 3: 使用 set 的迭代器
    std::set<double> numSet = {3.14, 1.41, 2.71};
    std::cout << "Set elements: ";
    for (std::set<double>::iterator it = numSet.begin(); it != numSet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 示例 4: 使用 map 的迭代器
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    std::cout << "Map elements: ";
    for (std::map<std::string, int>::iterator it = ageMap.begin(); it != ageMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
} 