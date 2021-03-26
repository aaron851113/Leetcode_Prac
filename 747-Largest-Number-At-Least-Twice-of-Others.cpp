// % g++ -std=c++11 -o x x.cpp
// % ./x
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = -1;
        int max = nums[0];
        int index = 0;
        for(int i=1 ; i<nums.size(); i++){
            if(nums[i]>max){
                max = nums[i];
                index = i;
            }
        }
        for(int i=0 ; i<nums.size(); i++){
                if(i!=index && max < nums[i]*2) return -1;
            }
        
        return index;
        
    }
};

int main(){
    vector<int> nums = {3,6,1,0};
    int ans = Solution().dominantIndex(nums);
    cout<<"ans = "<<ans<<endl;
    return 0;

}