// % g++ -std=c++11 -o 461 461.cpp
// % ./461
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> tobin(int a){
        vector<int> bin;
        bin.push_back(a&1);
        while((a>>=1)>0){
            bin.push_back(a&1);
        }
        return bin;
    } 
    int hammingDistance(int x, int y) {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
        int dis = 0;
        vector<int> bin_x = tobin(x);
        vector<int> bin_y = tobin(y);
        if (x>y) swap(x,y);
        int i;
        for(i=0 ; i< bin_x.size(); i++){
            if (bin_x[i]!=bin_y[i]) dis+=1;
        }

        for(int j=i ; j<bin_y.size(); j++)
        {
            if(bin_y[j]==1) dis+=1;
        }
        return dis;
    }
};

class Solution2 {
public:
    int hammingDistance(int x, int y) {
        // ^ = XOR
        int cnt = 0, result = x ^ y;
        while(result) result = result & (result - 1), cnt++;
        return cnt;
    }
};

int main(){
    int x = 3 , y = 1 ;
    int ans = Solution().hammingDistance(x,y);
    cout << "Ans :" << ans <<endl;
    return 0;
}