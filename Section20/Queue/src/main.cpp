//Section 20 Queue
#include <queue>
#include<iostream>


template<typename T>
void Display(std::queue<T> q)
{
    std::cout << "[";
    while(!q.empty())
    {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::queue<int>q;
    for(int i :{1, 2, 3, 4, 5})
        q.push(i);
    Display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    q.push(100);
    Display(q);

    q.pop();
    q.pop();
    Display(q);

    while(!q.empty())
        q.pop();
    Display(q);

    std::cout << "Size: " << q.size() << std::endl;
    
    q.push(10);
    q.push(100);
    q.push(1000);

    Display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    q.front() = 5;
    q.back() = 50000;
    Display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    

    return 0;
}
