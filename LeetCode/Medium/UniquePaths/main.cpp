// 62. Unique Paths
#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
                return 1;
        --m;
        --n;
        long long int ans=1,st_num=(m+1),st_den=1;
        while(n--)
        {
            ans*=st_num;
            ans/=st_den;
            ++st_num;
            ++st_den;
        }
        return ans;
    }
};

int main(){
    Solution Solve = Solution();
    int ans = Solve.uniquePaths(51,9);
    return 0;
}
