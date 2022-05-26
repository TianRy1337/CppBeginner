//Section 20 Vector
#include <iostream>
#include <vector>
#include <algorithm>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age):name{name},age{age}{}
    bool operator<(const Person &rhs)const
    {
        return this->age < rhs.age;
    }
    bool operator== (const Person &rhs)const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<< (std::ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::vector<T> &vec)
{
    std::cout << "[";
    for(const auto &element:vec)
        std::cout << element << " ";
    std::cout << "]" << std::endl;
}

// Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec)
{
    std::cout << "[";
    std::for_each(vec.begin(),vec.end(),[](int x) {std::cout << x <<" ";});
    std::cout << "]" <<std::endl;
}

void Test1()
{
    std::cout <<"\n Test1 =======================" <<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec = {2, 3, 4, 5};
    display2(vec);
    std::vector<int> vec1(25,100);
    display(vec1);
}

void Test2()
{
    std::cout <<"\n Test2 =======================" <<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    std::cout << "\nvec size : " << vec.size() << std::endl;
    std::cout << "vec max size : " << vec.max_size() << std::endl;
    std::cout << "vec capacity : " << vec.capacity() << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "\nvec size : " << vec.size() << std::endl;
    std::cout << "vec max size : " << vec.max_size() << std::endl;
    std::cout << "vec capacity : " << vec.capacity() << std::endl;

    vec.shrink_to_fit(); //C++ 11
    display(vec);
    std::cout << "\nvec size : " << vec.size() << std::endl;
    std::cout << "vec max size : " << vec.max_size() << std::endl;
    std::cout << "vec capacity : " << vec.capacity() << std::endl;

    vec.reserve(100);
    display(vec);
    std::cout << "\nvec size : " << vec.size() << std::endl;
    std::cout << "vec max size : " << vec.max_size() << std::endl;
    std::cout << "vec capacity : " << vec.capacity() << std::endl;

}

void Test3()
{
    std::cout <<"\n Test3 =======================" <<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);
}

void Test4()
{
    std::cout <<"\n Test4 =======================" <<std::endl;
    std::vector<Person> stooges;
    Person p1 {"Ryan",24};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Jack",45});
    display(stooges);

    stooges.emplace_back("Borky",24);
    display(stooges);
}

void Test5()
{
    std::cout <<"\n Test5 =======================" <<std::endl;
    std::vector<Person> stooges
    {
        {"Ryan",24},
        {"Kelly",32},
        {"Jack",45}
    };

    display(stooges);
    std::cout << "\nFront: " << stooges.front() <<std::endl;
    std::cout << "Back: " << stooges.back() <<std::endl;

    stooges.pop_back();
    display(stooges);

}

void Test6()
{
    std::cout <<"\n Test6 =======================" <<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display2(vec);

    vec.clear();
    display2(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    display2(vec);
    
    vec.erase(vec.begin(),vec.begin()+2);
    display2(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //erase all even numbers
    auto it = vec.begin();
    while(it != vec.end())
    {
        if(*it%2 == 0)
        {
            it = vec.erase(it);
        }
        else
        {
            it++;
        }
    }
    display2(vec);

}

void Test7()
{
    std::cout <<"\n Test7 =======================" <<std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};

    display2(vec1);
    display2(vec2);

    std::cout << std::endl;

    vec2.swap(vec1);
    display2(vec1);
    display2(vec2);
}

void Test8()
{
    std::cout <<"\n Test8 =======================" <<std::endl;
    std::vector<int> vec {1, 23, 3, 455, 88};
    display2(vec);

    std::sort(vec.begin(), vec.end());
    display2(vec);
}


// std::back_insert_contructs a back-insert iterator that inserts new elements
// at the end of the container it applied to. it's a special output iterator
// It's awesome!!!! and very efficient
//There is also a front_inserter we can use with deques and lists
// Copy one list to another using an iterator and back_inserter
void Test9()
{
    //std::back_inser
    std::cout <<"\n Test9 =======================" <<std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20};
    display(vec1);
    display(vec2);

    std::cout << std::endl;


    std::copy(vec1.begin(), vec1.end(),std::back_insert_iterator(vec2));
    display(vec1);
    display(vec2);
    
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x){return x%2 == 0;});
    display(vec1);
    display(vec2);

}

void Test10()
{
    //std::back_inser
    std::cout <<"\n Test10 =======================" <<std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};
    std::vector<int> vec3;

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3),[] (int x, int y){return x*y;});

    display(vec3);
}

void Test11()
{
    //std::back_inser
    std::cout <<"\n Test11 =======================" <<std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2 {100, 200, 300, 400};
    display(vec1);
    display(vec2);
    std::cout<<std::endl;

    auto it = std::find(vec1.begin(), vec1.end(), 11);
    if(it != vec1.end())
    {
        std::cout << "Inserting" << std::endl;
        vec1.insert(it,vec2.begin(),vec2.end());
    }
    else
    {
        std::cout << "Sorry number not found" <<std::endl;
    }
    display2(vec1);

}

int main()
{
    Test11();
    return 0;
}
