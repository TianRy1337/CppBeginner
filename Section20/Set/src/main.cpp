//Section 20 Set
#include <iostream>
#include <set>

class Person
{
    friend std::ostream &operator<< (std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person():name{"Unknown"}, age{0} {}
    Person(std::string name, int age)
        : name{name}, age{age}{}
    bool operator<(const Person &rhs)const
    {
        return this->age <rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return(this->name == rhs.name && this->age ==rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ":" <<p.age;
    return os;
}

template <typename T>
void Display(const std::set<T> &i)
{
    std::cout <<"[ ";
    for(const auto &elem:i)
    {
        std::cout << elem <<" ";
    }
    std::cout <<"]"<< std::endl;
}


void test1()
{
    std::cout << "\n Test1 ==================================" << std::endl;
    std::set<int> s1 {1, 32, 53, 14, 225};
    Display(s1);

    s1 = {1, 2, 3, 4, 5, 1, 2, 3, 4 ,5, 1, 1};
    Display(s1);

    s1.insert(0);
    s1.insert(10);

    Display(s1);

    if(s1.count(10))
        std::cout <<"10 is in the set." <<std::endl;
    else 
        std::cout <<"10 is Not in the set." << std::endl;

    auto it = s1.find(5);
    if(it!=s1.end())
        std::cout <<"Found: " << *it << std::endl;

    s1.clear();
    Display(s1);
}

void test2()
{
    std::cout << "\n Test2 ==================================" << std::endl;
    std::set<Person> stooges
    {
        {"Ryan",1},
        {"Jack",2},
        {"Claire",3}
    };
    Display(stooges);

    stooges.emplace("Jame",4);
    Display(stooges);

    stooges.emplace("Frank", 4); // Did not work --4 already exists
    Display(stooges);

    auto it = stooges.find(Person{"Jack", 2});
    if(it != stooges.end())
        stooges.erase(it);
    Display(stooges);

    it = stooges.find(Person{"XXX",123});

    if(it != stooges.end())
        stooges.erase(it);
    Display(stooges);

}

void test3()
{
    std::cout << "\n Test3 ==================================" << std::endl;
    std::set<std::string> s{"A", "B", "C"};
    Display(s);

    auto result = s.insert("D");
    Display(s);

    std::cout << std::boolalpha;
    std::cout << "First:" << *(result.first) << std::endl;
    std::cout << "Second:" << result.second << std::endl;

    std::cout <<std::endl;

    result = s.insert("A");
    Display(s);

    std::cout << std::boolalpha;
    std::cout << "First:" << *(result.first) << std::endl;
    std::cout << "Second:" << result.second << std::endl;

}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
