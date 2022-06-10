// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    ///Solution 1
    std::stack<char> S;
    std::queue<char> Q;

    for(int i=0; i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {
            S.push(tolower(s[i]));
            Q.push(tolower(s[i]));
        }
    }

    std::string Line1{};
    std::string Line2{};
    while(!Q.empty())
    {
        Line1 +=Q.front();
        Q.pop();
    }

    while(!S.empty())
    {
        Line2 +=S.top();
        S.pop();
    }
    if(Line1 == Line2)
        return true;
    else
        return false;


    ///Solution 2
    // std::stack<char> S;
    // std::queue<char> Q;
    // for(char c:s)
    // {
    //     if(std::isalpha(c))
    //     {
    //         c = std::toupper(c);
    //         Q.push(c);
    //         S.push(c);
    //     }
    // }
    // char c1{};
    // char c2{};

    // while(!Q.empty())
    // {
    //     c1 = Q.front();
    //     Q.pop();
    //     c2 = S.top();
    //     S.pop();
    //     if(c1!=c2)
    //         return false;
    // }
    // return true;

}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
