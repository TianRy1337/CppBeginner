#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSubSequence(string target, string myStr){
    if(target == myStr)
        return true;
    int Pos{0};
    string TmpStr{};
    for(int i=0; i<myStr.size(); i++){
        for(int j=Pos; j<target.size(); j++){
            if(myStr[i]==target[j]){
                Pos = j+1;
                TmpStr.push_back(myStr[i]);
                break;
            }
        }
    }
    if(TmpStr == myStr)
        return true;
    else
        return false;
}

class Solution {
public:
    int bs(vector<int> &arr, int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] <= x)
                start = mid + 1;
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans==-1 ? ans : arr[ans];
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        // int ans = 0;
        // for(int i = 0; i<words.size();i++){
        //     string str = words[i];
        //     if(isSubSequence(s,str))
        //         ans++;
        // }
        // return ans;
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int ans = words.size();
        
        for(auto w : words){
            int prev = -1;
            for(int j=0;j<w.size();j++){
                int x = bs(mp[w[j]],prev);
                if(x == -1){
                    ans--;
                    break;
                }
                else{
                    prev = x;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution solution = Solution();
    string S = "dsahjpjauf";
    vector<string> Words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    int ans = solution.numMatchingSubseq(S,Words);
    cout << ans << endl;
    return 0;
}


// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3
// Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
