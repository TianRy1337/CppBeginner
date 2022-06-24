#include <iostream>
#include <vector>
#include <algorithm>

int globalX{1000};

//Capture by value
//The global variable globalX cannot be captured because it's not
//within the reaching scope of the lanbda it can however still be accessed
//from within the lambda using normal name lookup rules
void Test1()
{
    std::cout << "\n Test1 =============================" << std::endl;
    int localX{100};
    auto l = [localX]()
    {
        std::cout << localX << std::endl;
        std::cout << globalX << std::endl;
    };
    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to
// the captured variable within the lambda body and not the actual variable 
void Test2()
{
    std::cout << "\n Test2 =============================" << std::endl;
    int x{100};
    auto l = [x]() mutable{
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes madew to the captured reference variable within the lambda body
// will change the actual variable.
void Test3()
{
    std::cout << "\n Test3 =============================" << std::endl;
    int x{100};

    auto l = [&x]() mutable
    {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x <<std::endl;
}

// Default capture by value - mutable
// Only variables used within the lanbda body are captured by value.
// The variable z is not captured by the lanbda
void Test4()
{
    std::cout << "\n Test4 =============================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=]() mutable
    {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

// Default capture by reference
// This time because all three variable - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void Test5()
{
    std::cout << "\n Test5 =============================" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [&]()
    {
        x+=100;
        y+=100;
        z+=100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    
}

// Default capture by value, capture y by reference
void Test6()
{
    std::cout << "\n Test6 =============================" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y]() mutable
    {
        x+=100;
        y+=100;
        z+=100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

//Default capture by reference, capture x and z by value
//Equivalent to test6
void Test7()
{
    std::cout << "\n Test7 =============================" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [&,x,z] () mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << "\n" << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// use for test8
class Person
{
    friend std::ostream &operator<< (std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age): name{name}, age{age}{}
    Person(const Person &p): name{p.name}, age{p.age}{}
    ~Person() = default;
    std::string get_name() const {return name;}
    void set_name(std::string name) {this->name = name;}
    int get_age() const{return age;}
    void set_age(int age){this->age = age;}

    auto changePerson1(){return [this](std::string new_name, int new_age){name = new_name; age = new_age;};}
    auto changePerson2(){return [=](std::string new_name, int new_age){name = new_name; age = new_age;};}
    auto changePerson3(){return [&](std::string new_name, int new_age){name = new_name; age = new_age;};}
};

std::ostream &operator<< (std::ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// Default capture by reference of the current object using [this]
//[=], [&], and [this] are equivalent when capturing an object's member variables - all are captured by reference
//Note that capturing this with [=] has been deprecated in C++20
//Also,C++20 allow [*this], which captures by value!
void Test8()
{
    std::cout << "\n Test8 =============================" << std::endl;
    Person person("Jack", 40);
    std::cout << person << std::endl;

    // Default capture [this]
    // This is the preferred way
    auto changePerson1 = person.changePerson1();
    changePerson1("Marry",25);
    std::cout << person << std::endl;

    // Defaut capture[=]
    // This has been deprecated in C++20
    auto changePerson2 = person.changePerson2();
    changePerson2("Blues",23);
    std::cout << person << std::endl;

    //Default capture[&]
    auto changePerson3 = person.changePerson3();
    changePerson3("Ryan", 24);
    std::cout << person << std::endl;
}

class Lambda
{
private:
    int y;
public:
    Lambda(int y):y(y){};
    void operator() (int x) const
    {
        std::cout << x+y << std::endl;
    };
};

// Lambda class equivalence example
void Test9()
{
    std::cout << "\n Test9 =============================" << std::endl;
    int y{100};

    Lambda lambda1(y);
    auto lambda2 = [y](int x) {std::cout << x+y << std::endl;};

    lambda1(200);
    lambda2(200);
}

// use for test10 
class People
{
    std::vector<Person> people;
    int max_people;
public:
    People(int max = 10):max_people(max){}
    People(const People &p) = default;
    void add(std::string name, int age)
    {
        people.emplace_back(name, age);
    }

    void set_max_people(int max)
    {
        max_people = max;
    }

    int get_max_people() const
    {
        return max_people;
    }
    
    // This method returns a vector of Person objects in 
    // people whose afe > max_age AND it limits the number of 
    // persons returned to be <= the member variable max_people.
    // Note that the lambda in this example captures this , by reference and by value
    std::vector<Person> get_people(int max_age)
    {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(), people.end(), std::back_inserter(result),
        [this, &count, max_age](const Person &p){return p.get_age() > max_age && ++count <= max_people;});
        return result;
    }
};

void Test10()
{
    std::cout << "\n Test10 =============================" << std::endl;
    People friends;
    friends.add("Rachel",30);
    friends.add("Monica", 28);
    friends.add("Phoebe", 31);
    friends.add("Joey", 31);
    friends.add("Chandler",32);
    friends.add("Ross", 32);

    auto result = friends.get_people(17);

    std::cout << std::endl;
    for(const auto &p :result)
        std::cout << p << std::endl;
    
    friends.set_max_people(3);

    result = friends.get_people(17);

    std::cout << std::endl;
    for(const auto &p:result)
        std::cout << p << std::endl;
    
    result = friends.get_people(50);

    std::cout << std::endl;
    for(const auto &p:result)
        std::cout << p <<std::endl;

}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    std::cout << std::endl;
    return 0;
}
