CXX = g++
CXXFLAGS = -std=c++11

all: vector_demo11 algorithm_demo iterator_demo

vector_demo11: 标准模板库（STL）/容器/vector_demo.cpp
	$(CXX) $(CXXFLAGS) -o vector_demo11 标准模板库（STL）/容器/vector_demo.cpp

algorithm_demo: 标准模板库（STL）/算法/algorithm_demo.cpp
	$(CXX) $(CXXFLAGS) -o algorithm_demo 标准模板库（STL）/算法/algorithm_demo.cpp

iterator_demo: 标准模板库（STL）/迭代器/iterator_demo.cpp
	$(CXX) $(CXXFLAGS) -o iterator_demo 标准模板库（STL）/迭代器/iterator_demo.cpp

clean:
	rm -f vector_demo algorithm_demo iterator_demo 