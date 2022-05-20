//Section 20 Class templates
#include <iostream>
#include <string>
#include <vector>

//Template classes are typically completely contained in header files
//So, we would have the template class in Item.h and no Item.cpp file would be used

template <typename T>
class Item
{
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value):name{name},value{value}{};
    std::string getName()const{return name;}
    T getValue() const {return value;}
};

template <typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item {"Ryan",100};
    std::cout << item.getName() << " " << item.getValue() << std::endl;

    Item<std::string> item2 {"Ryan","Student"};
    std::cout << item2.getName() << " " << item2.getValue() << std::endl;

    Item<Item<std::string>> item3{"Ryan",{"C++","Student"}};
    std::cout << item3.getName() << " " << item3.getValue().getName() << " "
              << item3.getValue().getValue() << std::endl;


    std::cout << "=============================" <<std::endl;
    std::vector<Item<double>> vec{};
    vec.push_back(Item<double>("A",100));
    vec.push_back(Item<double>("B",200));
    vec.push_back(Item<double>("C",300));

    for(const auto &item:vec)
        std::cout << item.getName() << " " << item.getValue() <<std::endl;

    std::cout << "=============================" <<std::endl;

    MyPair<std::string,int>p1{"Ryan",100};
    MyPair<int,double>p2{123,12.305};

    std::cout << p1.first <<"," <<p1.second << std::endl;
    std::cout << p2.first <<"," <<p2.second << std::endl;
    return 0;
}