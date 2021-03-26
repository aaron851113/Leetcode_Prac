// % g++ -std=c++11 -o 38 38.cpp
// % ./38
#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string str = "1";
        //做n次loop
        for(int k = 1; k < n; k++){
            string tmp;
            for(int i=0; i < str.size(); i++){
                int count = 1;
                while(i<str.size()-1 && str[i]==str[i+1]){
                    count++;
                    i++;
                }
                // int to string --> to_string(intvar)
                tmp += to_string(count) + str[i];
            }
            
            for(int i=0; i < tmp.size(); i++)cout<< tmp[i] <<' ';
            cout<<endl;
            str = tmp;
        }
        return str;
    }
};

int main(){
    int n = 4;
    string ans = Solution().countAndSay(n);
    cout<<endl;
}