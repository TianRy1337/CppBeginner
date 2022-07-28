#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        //!Soluction 1

        ////* Time Complexity O(n*log(n))
        ////* Space Complexity O(1).
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return (s == t);



        ////* Time Complexity O(n)
        ////* Space Complexity O(n)
        if(s.size()!= t.size())
            return false;
        unordered_map<char, int> mp1,mp2;
        for(char c: s)
            mp1[c]++;
        for(char c: t)
            mp2[c]++;
        for(int i = 0;i<s.size();i++){
            if(mp1[s[i]] != mp2[s[i]])
                return false;
        }
        return true;
    }
};
int main(){
    string s {"anagram"};
    string t {"nagram"};
    Solution Solve = Solution();
    bool ans = Solve.isAnagram(s,t);

    cout <<boolalpha << ans << endl;
}
