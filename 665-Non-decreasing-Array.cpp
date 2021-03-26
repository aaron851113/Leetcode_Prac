// % g++ -std=c++11 -o 665 665.cpp
// % ./665
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //用思路二
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i]>nums[i+1]){
                count++;

            }
        }
        if(count>=2) return false;
        return true;
    }
};

int main(){
    vector<int> nums = {4,2,3,6};
    bool ans = Solution().checkPossibility(nums);

    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}

/*
思路一：复制一份nums为temp。设置计数器count=0。从i=0到i=nums.size()-1遍历nums，
当我们发现当前节点比下一个节点大时，count++。如果i不是0，则尝试修改当前节点，
       将当前节点变小，并且将i-=2，回溯比较，以防当前节点的前一个节点比后一个节点大。
       遍历结束时，如果count小于2，则可返回true。count重置为0。
       从i=0到i=nums.size()-1遍历temp，当我们发现当前节点比下一个节点大时，count++，并尝试修改当前节点的下一个节点，
       使其变大。遍历结束时，如果count小于2，则可返回true。没有发生返回，则返回Ffalse。

思路二：设置计数器count=0。
       从i=1到i=nums.size()遍历nums。
       nums[i-1]>nums[i]时，修改数组不外乎有两种情况，使其中大的变成跟小的一样，或者使其小的变成跟大的一样。变大无所谓，对前面的顺序不会发生影响。
       但变小的话，容易对前面的序列发生影响，比如nus[i-2]>nums[i]，这样的话，如果是这种情况，或者i==1，则进行改小，其余的情况都进行改大。
       当count大于2时，直接返回false。否则为true。

思路三：对nums数组复制两份a1，a2。
       其中一份改大，另一份改小，且只改动一次就直接break，结束遍历。
       然后a1和对a1进行排序后进行比较，a2和对a2进行排序后进行比较，只要其中一个是相等的，就可返回true，否则返回false。这种Python写起来比较方便。
*/