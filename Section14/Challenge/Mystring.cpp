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
    //std::cout <<"Copy assignment"<<std::endl;
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
    //std::cout<<"Move Assignment"<<std::endl;
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
/////////////////////挑戰 local funcion//////////////////////////////////////////

//Make lowercase
Mystring Mystring::operator-()const
{
    char *buff = new char[std::strlen(str)+1];
    std::strcpy(buff,str);
    for(size_t i =0;i<std::strlen(buff);i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};

    delete[]buff;
    return temp;
}

// Equality
bool Mystring::operator==(const Mystring &rhs) const
{
    return(std::strcmp(str,rhs.str)==0);
}

// inequality
bool Mystring::operator!=(const Mystring &rhs) const
{
    return(std::strcmp(str,rhs.str)!=0);
}

// less than
bool Mystring::operator<(const Mystring &rhs) const
{
    return(std::strcmp(str,rhs.str)<0);
}

// greater than
bool Mystring::operator>(const Mystring &rhs) const
{
    return(std::strcmp(str,rhs.str)>0);
}

//Concatentate
Mystring Mystring::operator+(const Mystring &rhs)const
{
    char *buff = new char[std::strlen(str)+ std::strlen(rhs.str)+1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//Concatentate and return lhs
Mystring Mystring::operator+=(const Mystring &rhs)
{
    char *buff = new char[std::strlen(str)+std::strlen(rhs.str)+1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    str = buff;
    return str;
}

//repeat
Mystring Mystring::operator*(int iNum)const
{
    char *buff = new char[(std::strlen(str)*iNum)+1];
    std::strcpy(buff,str);
    for(size_t i = 0 ; i < iNum-1;i++)
    {
        std::strcat(buff,str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//repeat and return lhs;
Mystring Mystring::operator*=(int iNum)
{
    char *buff = new char[(std::strlen(str)*iNum)+1];
    std::strcpy(buff,str);
    for(size_t i = 0 ; i < iNum-1;i++)
    {
        std::strcat(buff,str);
    }
    str = buff;
    return str;
}

//++ pre-increment
Mystring &Mystring::operator++()
{
    for(size_t i =0;i<std::strlen(str);i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

//++ post-incremnet
Mystring Mystring::operator++(int)
{
    Mystring temp(*this);
    operator++();
    return temp;
}