// 890. Find and Replace Pattern
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    
    vector<int> found_Pattern(string pattern)
    {
	   // if string is empty return empty vector.
        if(pattern.size() == 0)
            return {};
        
        vector<int> v;
		
		// ind variable for keeping track of unique characters
        int ind = 0;
		
        unordered_map<char,int> mp;
        for(int i = 0; i<pattern.size(); ++i)
        {
			// if character not present in map, insert the char with an index,
			// increment index because for next unique character the index should be differnt.
           if(mp.find(pattern[i]) == mp.end())
           {
               mp.insert({pattern[i],ind++});
			   // also  push the index to v(numeric  pattern vector)
			   // mp[pattern[i]] gives the key to that character, here key is ind(which we are giving to every unique character)
               v.push_back(mp[pattern[i]]);
           }
            else
            {
				// if char is already in map than push index mapped to that character into the vector
                v.push_back(mp[pattern[i]]);
            }
        }
		// return numeric pattern
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
		// // store numeric patten of Pattern string in v
        // vector<int> v = found_Pattern(pattern);
        
        // int n = words.size();
        // vector<string> ans;
        
		// // iterating and comparing pattern of each word with v(numeric pattern of Pattern)
        // for(int i = 0; i<n; ++i)
        // {
        //     vector<int> pattern_word = found_Pattern(words[i]);
            
		// 	// if matched add words[i] to answer vector
        //     if(v == pattern_word)
        //         ans.push_back(words[i]);
        // }
        
        // return ans;
        vector<string> ans;
        for(auto x:words)
        {
            if(x.length()==pattern.length())
            {
                ans.push_back(x);
                unordered_map<char,char> mx;
                unordered_map<char,char> mp;
                for(int i=0;i<x.length();i++)
                {
                    if(mx.find(x[i])==mx.end() && mp.find(pattern[i])!=mp.end())
                    {
                        ans.pop_back();
                        i=x.length();
                    }
                    else if(mx.find(x[i])!=mx.end() && mp.find(pattern[i])==mp.end())
                    {
                        ans.pop_back();
                        i=x.length();
                    }
                    else if(mx.find(x[i])==mx.end() && mp.find(pattern[i])==mp.end())
                    {
                        mx[x[i]]=pattern[i];
                        mp[pattern[i]]=x[i];
                    }
                    else if(mx[x[i]]!=pattern[i] || mp[pattern[i]]!=x[i])
                    {
                        ans.pop_back();
                        i=x.length();
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solve = Solution();

    vector<string> inputs{"badc","abab","dddd","dede","yyxx"};
    vector<string> Ans{};
    Ans = solve.findAndReplacePattern(inputs,"baba");
    for( auto s :Ans)
        cout<< s << " ";
    return 0;
}
