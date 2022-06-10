//Section 20 Priority Queue
#include <iostream>
#include <queue>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person():name{"Unknown"},age{0}{}
    Person(std::string name, int age): name{name}, age{age}{}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os , const Person &p)
{
    os << p.name <<":" << p.age;
    return os;
}

template<typename T>
void Display(std::priority_queue<T>pq)
{
    std::cout <<"[";
    while(!pq.empty())
    {
        T elem = pq.top();
        pq.pop();
        std::cout << elem <<" ";   
    }
    std::cout  << "]" << std::endl;
}

void test1()
{
    std::cout << "\n Test1==============================" <<std::endl;
    std::priority_queue<int> pq;
    for(int i : {3, 4, 5, 656, 12, 66, 6767, 1234, 6, 10})
        pq.push(i);
    std::cout << "Size : " << pq.size() << std::endl;
    std::cout << "Top : " << pq.top() << std::endl;

    Display(pq);
    pq.pop();

    Display(pq);
}

void test2()
{
    std::cout << "\n Test2==============================" <<std::endl;
    std::priority_queue<Person> pq;
    pq.push(Person{"A",10});
    pq.push(Person{"B",1});
    pq.push(Person{"C",15});
    pq.push(Person{"D",52});
    pq.push(Person{"E",37});
    pq.push(Person{"F",24});

    Display(pq);
}

int main()
{
    test2();
    return 0;
}
