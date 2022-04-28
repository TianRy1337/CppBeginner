// Section 12 Dynamic Memory
#include <iostream>

using namespace std;

int main() 
{
    
    int *ptr {nullptr};
    ptr = new int;          // allocate the int on the heap
    cout << ptr << endl;    // use it
    delete ptr;             // release it
    
    size_t size{0};
    double *dptr {nullptr};
    
    cout << "How many temps? ";
    cin >> size;
    
    dptr = new double[size];    // allocate the storage on the heap
    cout << dptr << endl;       // use it
    delete [] dptr;             // release it
    
    return 0;
}

