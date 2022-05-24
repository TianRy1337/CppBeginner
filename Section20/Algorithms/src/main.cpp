//Section 20 Algorithms
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person
{
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string _name, int _age):name{_name},age{_age}{}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs)const
    {
        return(this->name == rhs.name && this->age ==rhs.age);
    }
};

//Find an element in a container
void FindTest()
{
    std::cout<<"\n==============================="<<std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    
    if(loc != std::end(vec))
        std::cout << "Found the number : " << *loc << std::endl;
    else
        std::cout << "Could not find the number." << std::endl;

    std::list<Person> players
    {
        {"Kevin",12},
        {"Ryan",24},
        {"BIG",32}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Ryan",22});
    if(loc1 != players.end())
        std::cout << "Found Ryan!" <<std::endl;
    else
        std::cout << "Ryan Not found" << std::endl;
}

//Count the number of element in a container
void CountTest()
{
    std::cout<<"\n==============================="<<std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 2, 3, 4, 1, 2};
    int num = std::count(vec.begin(),vec.end(),1);
    std::cout << num << " occurrences found" << std::endl;
}

//Count the number of occurences of an element in a container
//based in a predicate using a lanbda expreesion
void CountIfTest()
{
    std::cout<<"\n==============================="<<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 13, 20, 25, 31, 67, 100};
    

    //count only if the element is odd
    int num = std::count_if(vec.begin(),vec.end(),[](int x) {return x%2 != 0;});
    std::cout << num << " odd numbers found" <<std::endl;
    
    //count only if the element is even
    num = std::count_if(vec.begin(),vec.end(),[](int x) {return x%2 == 0;});
    std::cout << num << " even numbers found" <<std::endl;
}

// Replace occurrences of elements in a container
void ReplaceTest()
{
    std::cout<<"\n==============================="<<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    for(auto i:vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1,100);
    for(auto i:vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void AllOfTest()
{
    std::vector<int> vec {1, 3, 5, 7, 8, 9, 12};
    if(std::all_of(vec.begin(),vec.end(),[](int x ){return x>10;}))
        std::cout << "All the element are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;

    if(std::all_of(vec.begin(), vec.end(), [](int x){return x<20;}))
        std::cout << "All the element are < 20" << std::endl;
    else
        std::cout << "Not all the element are < 20 " << std::endl;
}

// Transform elements in a container - string in this example
void StringTransformTest()
{
    std::cout << "\n=========================" << std::endl;

    std::string str1{"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After transform: " << str1 << std::endl;
}

int main()
{
    StringTransformTest();
    return 0;
}
