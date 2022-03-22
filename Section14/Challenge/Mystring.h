#ifndef _MYSTRING_H_
#define _MYSTRING_H_
class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

    friend Mystring operator-(const Mystring &obj);
    friend bool operator==(const Mystring &lhs,const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs,const Mystring &rhs);
    friend bool operator<(const Mystring &lhs,const Mystring &rhs);
    friend bool operator>(const Mystring &lhs,const Mystring &rhs);
    friend Mystring operator+(const Mystring &lhs , const Mystring &rhs);
    friend Mystring operator+=(Mystring &lhs , const Mystring &rhs);
    friend Mystring operator*(const Mystring &obj , int iNum);
    friend Mystring operator*=(Mystring &lhs ,int iNum);
    friend Mystring &operator++(Mystring &obj);
    friend Mystring operator++(Mystring &obj, int);   
private:
    char *str;  //pointer to a char[] that hold a C-style string
public:
    Mystring();                                 //No-args constructor
    Mystring(const char *s);                    //Overloaded constructor
    Mystring(const Mystring &source);           //Copy constructor
    Mystring(Mystring &&source);                //Move constructor
    ~Mystring();                                //Destructor

    Mystring &operator=(const Mystring &rhs);   //Copy assignment
    Mystring &operator=(Mystring &&rhs);        //Move assignment

    /*Mystring operator-()const;                      // make lowercase
    bool operator==(const Mystring &rhs)const;      // Equalily
    bool operator!=(const Mystring &rhs)const;      // inequality
    bool operator<(const Mystring &rhs)const;       // Less than
    bool operator>(const Mystring &rhs)const;       // greater than
    Mystring operator+(const Mystring &rhs)const;   // concatenate
    Mystring operator+=(const Mystring &rhs);       // concatenate and return lhs
    Mystring operator*(int iNum)const;              // repeat
    Mystring operator*=(int iNum);                  // repeat and return lhs;
    Mystring &operator++();                    // pre-increment;
    Mystring operator++(int);                          // post-increment;
    */
    void display() const;
    int get_length() const;                     //getters
    const char *get_str() const;
};
#endif