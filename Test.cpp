#include <iostream>
using namespace std;
int main()
{
    int vals[] {1,2,3,4,5};
    for(auto val:vals)
    {
        cout << val << endl;        
    }
    return 0;
}