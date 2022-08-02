// 378. Kth Smallest Element in a Sorted Matrix
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // //* Solution 1 brute force 
        // vector<int>ans{};

        // for(int i = 0; i <matrix.size();i++){
        //     for(int j= 0; j<matrix[i].size();j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // return ans[k-1];

        // //* Solution 2 priority_queue
        // priority_queue<int> pq;
        // for(int i=0; i<matrix.size(); i++) {
        //     for(int j=0; j<matrix[0].size(); j++) {
        //         pq.push(matrix[i][j]);
        //         if(pq.size() > k)
        //             pq.pop();
        //     }
        // }
        // return pq.top();


        //* Solution 3 Binary Search
        int matrixSize = matrix.size();
        int low = matrix[0][0];
        int high = matrix[matrixSize-1][matrixSize-1];
        int mid{};
        int tmp{};
        int count{};

        while(low < high){
            mid = low + (high - low)/2;
            tmp = matrixSize-1;
            count = 0;

            for(int i =0; i<matrixSize ;i++){
                while(tmp>=0 && matrix[i][tmp] > mid){
                    tmp --;
                }
                count += (tmp+1);
            }
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;

    }
};

int main(){
    Solution Solve = Solution();
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int ans = Solve.kthSmallest(matrix,8);
    cout << ans << endl;
    return 0;
}
