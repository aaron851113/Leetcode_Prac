// % g++ -std=c++11 -o 806 806.cpp
// % ./806
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans = {1,0};
        int count = 0;
        int tmp_len = 0;
        for(int i=0; i<s.size(); i++){
            tmp_len = widths[s[i]-'a'];
            if(count + tmp_len > 100){
                count = tmp_len;
                ans[0]+= 1;
            }
            else count += tmp_len;
        }
        ans[1] = count;
        return ans;
    }
};

int main(){

    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> ans(2);
    ans = Solution().numberOfLines(widths, s);
    cout << "ans = " << ans[0] << ' ' << ans[1] << endl;

    return 0;
}
