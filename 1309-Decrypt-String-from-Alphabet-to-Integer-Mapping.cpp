// % g++ -std=c++11 -o x x.cpp
// % ./x
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i = 0; i < s.size() ; i++){
            // add to ans;
            if(s[i]!='#'){
                ans += 'a'+(s[i] - '0' - 1);
            }
            else{
                ans.erase(ans.size()-2,2); //delete two char
                string substr = s.substr(i-2,2);
                cout << substr << ' ' ;
                ans += 'a'+ (stoi(substr)-1);
                                
            }
        }
        return ans;
    }
};

int main(){
    string s = "10#11#12";
    string ans = Solution().freqAlphabets(s);
    cout<<"ans = "<<ans<<endl;
    return 0;
}