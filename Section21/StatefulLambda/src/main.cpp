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

    auto l = [=, &y]()
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
//
void Test7()
{
    std::cout << "\n Test7 =============================" << std::endl;
}


void Test8()
{
    std::cout << "\n Test8 =============================" << std::endl;
}

void Test9()
{
    std::cout << "\n Test9 =============================" << std::endl;
}

void Test10()
{
    std::cout << "\n Test10 =============================" << std::endl;
}

int main()
{
    // Test1();
    // Test2();
    // Test3();
    // Test4();
    Test 5();
    std::cout << std::endl;
    return 0;
}
