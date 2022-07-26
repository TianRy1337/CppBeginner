#include<iostream>
#include<string>
int romanToInt(std::string s) 
{
    int val{},in{},sum{};
    for(int i=0;i<s.size();i++)
    {
        if(i==0)
        {
            if(s[i]=='I')
            {
                in=1;
                val=1;
                sum+=val;
            }
            if(s[i]=='V')
            {
                    in=5;
                val=5;
                sum+=val;
            }
            if(s[i]=='X')
            {
                    in=10;
                val=10;
                sum+=val;
            }
            if(s[i]=='L')
            {
                    in=50;
                val=50;
                sum+=val;
            }
            if(s[i]=='C')
            {
                    in=100;
                val=100;
                sum+=val;
            }
            if(s[i]=='D')
            {
                    in=500;
                val=500;
                sum+=val;
            }
            if(s[i]=='M')
            {
                    in=1000;
                val=1000;
                sum+=val;
            }
        }
        else
        {
            if(s[i]=='I')
            {
                val=1;
                sum+=val;
            }
            if(s[i]=='V')
            {

                val=5;
                sum+=val;
            }
            if(s[i]=='X')
            {

                val=10;
                sum+=val;
            }
            if(s[i]=='L')
            {

                val=50;
                sum+=val;
            }
            if(s[i]=='C')
            {

                val=100;
                sum+=val;
            }
            if(s[i]=='D')
            {

                val=500;
                sum+=val;
            }
            if(s[i]=='M')
            {

                val=1000;
                sum+=val;
            }
        }
        if(in<val)
        {
            sum-=in;
            sum-=in;
        }
        in=val;
        
    }
    return sum;
}

int main()
{
    int ans = romanToInt("IC");
    std::cout << ans << std::endl;
    return 0;
}
