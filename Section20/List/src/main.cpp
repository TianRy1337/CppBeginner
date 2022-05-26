//Section 20 List
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
 
 class Person
 {
    friend std::ostream &operator<< (std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person():name{"Unknown"}, age{0}{}
    Person(std::string name, int age):name{name}, age{age}{}
    bool operator<(const Person &rhs) const
    {
        return this->age<rhs.age;
    }
    bool operator ==(const Person &rhs)const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
 };

 std::ostream &operator<< (std::ostream &os, const Person &p)
 {
    os << p.name <<":" << p.age;
    return os;
 }


template<typename T>
void Display(const std::list<T> &_List)
{
    std::cout << "[";
    for(const auto &element:_List)
        std::cout << element <<" ";
    std::cout << "]" << std::endl;
}

void Test1()
{
    std::cout << "\n Test1 ======================="<< std::endl;
    std::list<int> L1{1, 2, 3, 4, 5};
    Display(L1);

    std::list<std::string> L2;
    L2.push_back("Back");
    L2.push_front("Front");

    Display(L2);

    std::list<int> L3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Display(L3);

    std::list<int> L4(10, 100);
    Display(L4);


}

void Test2()
{
    std::cout << "\n Test2 ======================="<< std::endl;
    std::list<int> L1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Size : " << L1.size() << std::endl;
    std::cout << "Front : " << L1.front() << std::endl;
    std::cout << "Back : " << L1.back() << std::endl;

    L1.clear();
    Display(L1);

    std::cout << "Size : " << L1.size() << std::endl;
}

void Test3()
{
    std::cout << "\n Test3 ======================="<< std::endl;
    std::list<int> L1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Display(L1);
    
    L1.resize(5);
    Display(L1);

    L1.resize(10);
    Display(L1);

    std::list<Person> persons;
    persons.resize(5);
    Display(persons);
}

void Test4()
{
    std::cout << "\n Test4 ======================="<< std::endl;
    std::list<int> L1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Display(L1);

    auto it = std::find(L1.begin(), L1.end(), 5);
    if(it != L1.end())
    {
        L1.insert(it,100);
    }
    Display(L1);

    std::list<int> L2{1000, 2000, 3000};
    L1.insert(it, L2.begin(), L2.end());
    Display(L1);

    std::advance(it, -4);
    std::cout << *it << std::endl;

    L1.erase(it);
    Display(L1);

}

void Test5()
{
    std::cout << "\n Test5 ======================="<< std::endl;
    std::list<Person> stooges
    {
        {"Ryan", 24},
        {"Kelly", 14},
        {"Jack", 45}
    };

    Display(stooges);
    std::string name;
    int age{};
    std::cout << "\nEnthe the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    stooges.emplace_back(name, age);
    Display(stooges);

    auto it = std::find(stooges.begin(), stooges.end(), Person{"Kelly", 14});
    if(it != stooges.end())
    {
        stooges.emplace(it,"Black", 18);
    }
        Display(stooges);
}

void Test6()
{
    std::cout << "\n Test6 ======================="<< std::endl;
    std::list<Person> stooges
    {
        {"Ryan", 24},
        {"Kelly", 14},
        {"Jack", 45}
    };
    Display(stooges);
    stooges.sort();
    Display(stooges);
}

int main()
{
    Test6();
    return 0;
}
