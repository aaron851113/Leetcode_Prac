#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
Target : Stack structure

stack.push()
stack.pop()
stack.top()
stack.empty()
*/

class Solution_Stack {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        
        int j = 0 ;
        for (int i = 0 ; i < pushed.size() ; i++)
        {
            stack.push(pushed[i]);
            while(!stack.empty() && stack.top() == popped[j])
            {
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> index(5);
        for(int i = 0; i < pushed.size(); i++)
        {
            index[pushed[i]] = i;
        }
        
        int max_reversed = 0;
        int min_idx = INT_FAST32_MAX;

        for(int num : popped)
        {
            int idx = index[num];

            if(idx > max_reversed) max_reversed = idx - 1;
            else if (idx < max_reversed) return false;
            else min_idx = min(min_idx, idx);
        }
        return true;        
    }
};

int main(){

    vecotr<int> pushed = [1,2,3,4,5];
    vecotr<int> popped = [4,5,3,2,1];
    bool ans1 = Solution_Stack().validateStackSequences(pushed, popped);
    cout << ans1 ;
    bool ans2 = Solution().validateStackSequences(pushed, popped);
    cout << ans2 ;

}