// % g++ -std=c++11 -o 171 171.cpp
// % ./171
#include<iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int sum = 0;
        int length = columnTitle.size();

        for(int i = 0; i < length; i++)
        {
            sum += ((columnTitle[length-i-1]-'A'+1) * pow(26, i));
        }

        return sum;
    }
};

int main(){
    string input = "AAB";
    int ans = Solution().titleToNumber(input);
    cout<< ans <<endl;
}