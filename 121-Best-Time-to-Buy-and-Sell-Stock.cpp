// % g++ -std=c++11 -o x x.cpp
// % ./x
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int profit = 0;
        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i]<min_price){
                min_price = prices[i];
                cout<<"min_price"<<min_price<<endl;
                continue;
            }
            else{
                int tmp_profit = prices[i] - min_price;
                if (tmp_profit > profit){
                    profit = tmp_profit;
                    cout<<"profit"<<profit<<endl;
                }
            }
            
        }

        return profit;
    }
};

int main(){
    
    vector<int> v = {7,1,5,3,6,4};
    int ans = Solution().maxProfit(v);

    cout<<"ans = "<<ans<<endl;
    return 0;

}