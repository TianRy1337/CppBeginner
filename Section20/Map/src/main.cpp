//Section 20 Map
#include<iostream>
#include<map>
#include<set>

void display(const std::map<std::string, std::set<int>> &m)
{
    std::cout << "[";
    for(const auto &elem:m)
    {
        std::cout << elem.first << ":[";
        for(const auto &set_elem :elem.second)
            std::cout <<set_elem <<" ";
        std::cout << "]";
    }
    std::cout << "] " << std::endl;
}

template<typename T1, typename T2>
void display(const std::map<T1, T2> &L)
{
    std::cout << "[ ";
    for(const auto &elem:L)
        std::cout << elem.first << ":" << elem.second << " ";
    std::cout << "] " << std::endl;
}

void test1()
{//Maps
    std::cout << "\n Test1 ===============================" <<std::endl;
    std::map<std::string, int>m{
        {"Larry",3},
        {"Moe",1},
        {"Curly",2}
    };
    display(m);
    
    m.insert(std::pair<std::string, int>("Anna", 10));
    display(m);

    m.insert(std::make_pair("Joe",5));
    display(m);

    m["Ryan"] = 18;
    display(m);

    m["Ryan"] += 6;
    display(m);

    m.erase("Ryan");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Ryan: " << m.count("Ryan") << std::endl;

    auto it = m.find("Larry");
    if(it != m.end())
        std::cout << "Found: " << it->first << " , " << it->second << std::endl;
    
    m.clear();
    display(m);

}

void test2()
{
    std::cout << "\n Test2 =====================================" << std::endl;
    std::map<std::string, std::set<int>> grades{
        {"Larry",{100,90}},
        {"Jack",{94}},
        {"Amber",{80, 90, 100}}
    };
    display(grades);

    grades["Larry"].insert(95);
    display(grades);

    auto it = grades.find("Jack");
    if(it != grades.end())
    {
        it->second.insert(1000);
    }
    display(grades);


}


int main()
{
    test2();
    return 0;
}
