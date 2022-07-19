#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> _Vec{};
        vector<int> _InsideVec{};
        for(int i=0; i<numRows; i++){
            _InsideVec.clear();
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)
                    _InsideVec.push_back(1);
                else{
                    _InsideVec.push_back(_Vec[i-1][j]+_Vec[i-1][j-1]);
                }
            }
            _Vec.push_back(_InsideVec);
        }
        return _Vec;
    }
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ans(numRows, vector<int>());
	// 	ans[0].push_back(1);
    //     for (size_t i = 1; i < numRows; i++) {
    //         for (size_t j = 0; j < i + 1; j++) {
    //             auto value = 1;
    //             if (0 < j && j < i) {
    //                 value = ans[i - 1][j - 1] + ans[i - 1][j];
    //             }
    //             ans[i].push_back(value);
    //         }
    //     }
    //     return ans;
    // }
};

void printTriangle(vector<vector<int>> &_vec){
    cout <<"[";
    for (int i = 0; i < _vec.size(); i++)
    {
        cout <<"[";
        for (int j = 0; j < _vec[i].size(); j++)
        {
            cout << _vec[i][j];
            if(j !=_vec[i].size()-1)
                cout << ",";
        }
        cout <<"]";
        if(i!=_vec.size()-1)
            cout <<",";
    }
    cout <<"]";
}

int main(){
    Solution solution{};
    vector<vector<int>> Triangle =solution.generate(7);
    printTriangle(Triangle);
    return 0;
}
