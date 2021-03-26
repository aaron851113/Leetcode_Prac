// % g++ -std=c++11 -o 1277 1277.cpp
// % ./1277

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        if(matrix.empty())return 0;

        for(int i = 0; i < matrix.size() ; i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(i != 0 && j != 0 && matrix[i][j] == 1)
                    matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + matrix[i][j];
                ans += matrix[i][j];
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> nums = {{0,1,1,1},
                                {1,1,1,1},
                                {0,1,1,1}};
    int ans = Solution().countSquares(nums);
    cout << "Ans :" << ans <<endl;
    return 0;
}
