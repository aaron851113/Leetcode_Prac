#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp_sum = 0;
        int all_sum = nums[0];

        for( int i = 0 ; i < nums.size(); i++){
            if ( tmp_sum >= 0){
                tmp_sum += nums[i];
            }
            else{
                tmp_sum = nums[i];
            }
            
            if ( tmp_sum > all_sum){
                all_sum = tmp_sum;
            }
        }
        return all_sum;
    }
};