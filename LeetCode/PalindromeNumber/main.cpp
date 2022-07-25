#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // Answer 1
        // auto str = to_string(x);
        // std::deque<char> D;
        // std::deque<char> _D;
        // for(int i=0; i<str.size(); i++){
        //     D.push_back(str[i]);
        //     _D.push_front(str[i]);
        // }
        // if (D == _D){
        //     return true;
        // }
        // return false;

        // Answer 2
        long long ans=x;
        long long rev=0;
        while(x>0){
            rev=rev*10+x%10;
            x=x/10;
        }
        if(rev==ans){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Solution Solve = Solution();
    bool ans = Solve.isPalindrome(1221);

    cout << ans << endl;
    return 0;
}
