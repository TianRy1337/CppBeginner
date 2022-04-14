#include <iostream>
#include "Mystring.h"
using namespace std;

int main ()
{
    Mystring empty;
    Mystring Larry("Larry");
    Mystring Stooge{Larry};
    empty.display();
    Larry.display();
    Stooge.display();
}