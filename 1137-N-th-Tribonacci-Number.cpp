// % g++ -std=c++11 -o 1137 1137.cpp
// % ./1137
#include<iostream>
#include<vector>
using namespace std;

class Solution_recursion{
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n==2) return 1;
        
        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};

class Solution{
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 1;
        int last0 = 0;
        int last1 = 1;
        int last2 = 1;
        int now = 0;
        cout<<0<<' '<<1<<' ';
        for(int i = 2; i < n; ++i){
            now = last0+last1+last2;
            cout<<now<<' ';
            last0 = last1;
            last1 = last2;
            last2 = now; 
        }
        cout<<endl;
        return now;
    }
};

int main(){
    int nums = 25;
    int ans = 0; 
    ans = Solution().tribonacci(nums);
    cout<<"forloop ans = "<<ans<<endl;

    ans = Solution_recursion().tribonacci(nums);
    cout<<"recursion ans = "<<ans<<endl;

    return 0;
}