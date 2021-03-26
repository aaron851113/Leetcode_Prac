// % g++ -std=c++11 -o 693 693.cpp
// % ./693
#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 取第一個位
        int r = n & 1;
        // >> 1 (右移一位 = /2)
        // (ex : 10010 >> 1  =  1001 )
        // while((n>>=1) != 0)
        while((n/=2) != 0){
            int t = n & 1;
            if (t==r) return false;
            r = t ;
        }
        return true;
    }
};

int main(){
    int n = 10 ;
    bool ans = Solution().hasAlternatingBits(n);
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}