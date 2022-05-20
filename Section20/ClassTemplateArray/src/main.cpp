// Section 20 Class template - Array

//Note: Since C++ 11 the STL has std::array which is a template-base array class
//Use std::array instead of raw arrays whenever possible

//Note that we can have non-type template parameters
//That's what N is in this class

#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
    int size{N};
    T values[N];

    friend std::ostream &operator<< (std::ostream &os, const Array<T, N> &arr)
    {
        os <<"[ ";
        for(const auto &val:arr.values)
            os << val <<" ";
        os << "]" <<std::endl;
        return os;
    }
public:
    Array() = default;
    
    Array(T initVal)
    {
        for(auto &item:values)
            item = initVal;
    }

    void Fill(T val)
    {
        for(auto &item:values)
            item = val;
    }

    int getSize() const
    {
        return size;
    }

    T &operator[](int index)
    {
        return values[index];
    }
};

int main()
{
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.Fill(0);
    std::cout << "The size of num is: " << nums.getSize() << std::endl;
    std::cout << nums <<std::endl;

    nums.Fill(10);
    std::cout << nums <<std::endl;

    nums[0] = 1000;
    nums[3] = 1337;
    std::cout << nums << std::endl;

    Array<int, 100> nums2{1};
    std::cout << "The size of nums2 is : " << nums2.getSize() <<std::endl;
    std::cout << nums2 <<std::endl;

    Array<std::string, 10> strings(std::string{"Ryan"});
    std::cout << "The size of strings is" <<strings.getSize() << std::endl;
    std::cout << strings << std::endl;

    return 0;
}