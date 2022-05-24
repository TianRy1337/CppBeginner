// Section 20 std::array
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  //for more algorithms like accumulate

// Display the array --note the size MUST be included
// when passing a std::array to a function

void display(const std::array<int,5> &arr)
{
    std::cout <<"[";
    for(auto element:arr)
    {
        std::cout << element << " ";
    }
    std::cout<<"]"<<std::endl;

}

void Test1()
{
    std::cout <<"\n Test1 ===================" << std::endl;
    std::array<int,5> arr1{1, 2, 3, 4, 5};
    std::array<int,5> arr2;
    display(arr1);
    display(arr2);

    arr2 = {10, 20, 30, 40, 50};
    display(arr1);
    display(arr2);

    std::cout <<"Size of arr1 is " << arr1.size() <<std::endl;
    std::cout <<"Size of arr2 is " << arr2.size() <<std::endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "Back of arr2: " << arr2.back() << std::endl;

}

void Test2()
{
    std::cout <<"\n Test2 ===================" << std::endl;
    std::array<int,5> arr1 {1, 2, 3, 4, 5};
    std::array<int,5> arr2 {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);

}

void Test3()
{
    std::cout <<"\n Test3 ===================" << std::endl;
    std::array<int,5> arr1 {1, 2, 3, 4, 5};

    int *ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000;

    display(arr1);
}

void Test4()
{
    std::cout <<"\n Test4 ===================" << std::endl;
    std::array<int,5> arr1 {2, 4, 5, 1, 3};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void Test5()
{
    std::cout <<"\n Test5 ===================" << std::endl;
    std::array<int,5> arr1 {1, 2, 3, 4, 5};
    
    std::array<int,5>::iterator minNum = std::min_element(arr1.begin(), arr1.end());
    auto maxNum = std::max_element(arr1.begin(), arr1.end());
    std::cout << "min: " << *minNum << ", max :" <<*maxNum <<std::endl;
}

void Test6()
{
    std::cout <<"\n Test6 ===================" << std::endl;
    std::array<int,5> arr1 {1, 2, 3, 3, 5};

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if(adjacent != arr1.end())
        std::cout << "Adjacent element found with value:" << *adjacent <<std::endl;
    else
        std::cout << "No adjacent elements found"<<std::endl;
}

void Test7()
{
    std::cout <<"\n Test7 ===================" << std::endl;
    std::array<int,5> arr1 {1, 2, 3, 3, 5};

    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements is arr1 is : " << sum << std::endl; 

}

void Test8()
{
    std::cout <<"\n Test8 ===================" << std::endl;
    std::array<int, 10> arr{1, 2, 3, 1, 2, 3, 4, 5, 1, 2};
    int count = std::count(arr.begin(), arr.end(), 3);
    std::cout << "Found 3 : " << count << std::endl;
}

void Test9()
{
    std::cout <<"\n Test9 ===================" << std::endl;
    std::array<int, 10> arr{1, 2, 3, 1, 7, 9, 5, 7, 1, 6};
    //find how many numbers are betwwen 1~5

    int count = std::count_if(arr.begin(), arr.end(), [](int x){return x>1 && x<5;});

    std::cout << "Found " << count << " matchs" << std::endl;
}


int main()
{
    Test9();
    return 0;
}
