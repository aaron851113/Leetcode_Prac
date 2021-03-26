// % g++ -std=c++11 -o 962 962.cpp
// % ./962
#include<iostream>
#include<vector>
using namespace std;

bool mycompare(vector<int>& A, vector<int>& B){
        return A[1] < B[1];
}

class SolutionExample {
public:
    int maxWidthRamp(vector<int>& A) {
        const int N = A.size();
        vector<vector<int>> B(N, vector<int>(2));
        for (int i = 0; i < N; ++i) {
            B[i][0] = A[i];
            B[i][1] = i;
        }
        
        sort(begin(B), end(B));
        
        int ans = 0;
        for (int k = 1, i = B[0][1]; k < N; ++k) {
            int j = B[k][1];
            if (i < j) ans = max(ans, j - i);
            i = min(i, j);
        }
        return ans;
    }
};

class Solution {
public:
    
    int maxWidthRamp(vector<int>& A) {
        int N = A.size();
        // 建立一個 2D array B[N][2]
        // B[N][0]放index
        // B[N][1]放value
        vector<vector<int>>B(N, vector<int>(2));
        //存放值
        for(int i = 0; i < N; ++i){
            B[i][0] = i;
            B[i][1] = A[i];
        }
        //根據B[N][1](value)排序
        sort(B.begin(), B.end(), mycompare);
        cout<<"after sort"<<endl;
        for(int i=0 ; i< N; ++i) {
            cout << B[i][0] <<' ';
        }
        cout<<endl;
        for(int i=0 ; i< N; ++i) {
            cout << B[i][1] <<' ';
        }
        cout<<endl;

        //進行算法
        int ans = 0;
        for (int k = 1, i = B[0][0]; k<N ; ++k){
            int j = B[k][0];
            //如果index順序合理才能做計算
            if (i < j) ans = max(ans, j-i); //j-i = 取width ramp
            
            i = min(i,j);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0};

    for(int i=0 ; i<nums.size(); ++i) {
        cout << i <<' ';
    }
    cout<<endl;

    for(int i=0 ; i<nums.size(); ++i) {
        cout << nums[i] <<' ';
    }
    cout<<endl;

    int ans = Solution().maxWidthRamp(nums);
    cout<<"ans="<<ans<<endl;

    return 0;
}