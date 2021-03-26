// % g++ -std=c++11 -o 1539 1539.cpp
// % ./1539
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int miss = 0;
        for(int i = 1; i < arr.size()+k+1 ; ++i){
            // python 中 in 的寫法 --> C++ = #include <algorithm> cout(arr.begin(), arr.end(), key)
            if (count(arr.begin(), arr.end(), i)){
                continue;
            }
            else{
                miss++;
            }
            if (miss==k){
                ans = i;
            }
        }
        return ans ;
    }
};

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    int ans = Solution().findKthPositive(arr, k);
    cout<<"ans = "<<ans<<endl;
    return 0; 
}