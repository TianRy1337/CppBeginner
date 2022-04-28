// Section 12 Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *largeInt(int *A, int *B)
{
    if(*A > *B)
    {
        return A;
    }
    else
    {
        return B;
    }
}

int main() 
{
    int a{100};
    int b{50};

    int *ptr{nullptr};

    ptr = largeInt(&a,&b);

    cout << *ptr << endl;
    cout << ptr << endl;

    return 0;
}

