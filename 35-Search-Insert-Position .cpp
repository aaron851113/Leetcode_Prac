// % g++ -std=c++11 -o 35 35.cpp
// % ./35
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int n = nums.size();
        if (target<nums[0]) return 0;

        if (target>nums[n-1]) return n; 

        int ans = 0;
        for(int i = 0; i<nums.size(); ++i){
            
            if (target==nums[i]){
                ans = i;
                break;
            }
            
            if ( target>nums[i] && target<nums[i+1]){
                ans = i+1;
                break;
            }
            
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int ans = Solution().searchInsert(nums, target);
    cout<<"ans = "<<ans<<endl;
    return 0;
}