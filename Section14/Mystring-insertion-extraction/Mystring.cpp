#include<cstring>
#include<iostream>
#include "Mystring.h"

//No-args constructor
Mystring::Mystring():str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

//Overloaded constructor
Mystring::Mystring(const char *s):str{nullptr}
{
    if(s==nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s)+1];
        std::strcpy(str,s);   
    }
}

//Copy constructor
Mystring::Mystring(const Mystring &source):str{nullptr}
{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}

//Move Constructor
Mystring::Mystring(Mystring &&source):str(source.str)
{
    source.str = nullptr;
    std::cout<<"Move constructor used"<<std::endl;
}


//Destructor
Mystring::~Mystring()
{
    delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout <<"Copy assignment"<<std::endl;
    if(this==&rhs)
    {
        return *this;
    }
    delete[] str;
    str = new char[std::strlen(rhs.str)+1];
    std::strcpy(str,rhs.str);
    return *this;
}

//Move Assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout<<"Move Assignment"<<std::endl;
    if(this == &rhs)
    {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const
{
    std::cout<<str<<":"<<get_length()<<std::endl;
}

// getters
int Mystring::get_length()const{return std::strlen(str);}
const char *Mystring::get_str() const {return str;}

//overloaded insertion operator
std::ostream &operator<<(std::ostream &os , const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

//overloaded extraction operator
std::istream &operator>>(std::istream &in , Mystring &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};//Move assignment
    delete []buff;
    return in ;
}
