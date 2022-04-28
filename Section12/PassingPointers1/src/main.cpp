// Section 12 Passing Pointers 1
#include <iostream>

using namespace std;


void double_data(int *iPtr) 
{
   *iPtr *= 2;	
}

int main() 
{
    int value {10};
    int *ptr {nullptr};
    
    cout << "Value: " << value << endl;
    double_data(&value);
    cout << "Value: " << value << endl;

    cout << "===============" << endl;
    ptr = &value;
    double_data(ptr);
    cout << "Ptr Value: " << *ptr << endl;
    cout << "Value: " << value << endl;

    return 0;
}