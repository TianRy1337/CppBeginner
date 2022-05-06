#include <iostream>
using namespace std;

int square(int &n)
{
	return n*n;
}

int main()
{

    int a = -25;
    //square(100);
    

    cout << square(a) << endl;

    return 0;
}