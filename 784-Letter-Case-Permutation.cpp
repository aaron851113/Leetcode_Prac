#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
DFS
Time : O(n*2^l)
Space : O(n)+O(c*2^l)

Upper case : 65 - 90
Lower case : 97 - 122

'a' ^= (1<<32) --> 'A'
'A' ^= (1<<32) --> 'a'

def DFS(s, i)
    if i == len(s): ans.append(s)
    DFS(s, i+1)
    if s[i] is letter:
        toggle(s[i]) //create branch # s[i] ^= (1<<32)
        DFS(s, i+1)
        
        toggle(s[i+1])
*/
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
            vector<string> ans;
            dfs(s, 0, ans);
            return ans;
        }
        private:
        void dfs(string& s, int i, vector<string>& ans) {
            if (i == s.length())
            {
                ans.push_back(s);
                return;      
            }
            dfs(s, i + 1, ans);    
            if (isalpha(s[i]))          
            {
                s[i] ^= (1 << 5);
                dfs(s, i + 1, ans);
                //s[i] ^= (1 << 5);
            }
            
        }
    };

int main(){
    string s = "a1b2";
    vector<string> output = Solution().letterCasePermutation(s);
    for (int i = 0; i<=output.size() ; ++i)
        cout << output[i] << ' ';

}