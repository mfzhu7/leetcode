#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void print(vector<int> nums){
    for (auto i: nums){
        cout << i << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i <= prices.size() - 1; i++){
            max_profit = ((prices[i] - min_price) > max_profit) ? (prices[i] - min_price): max_profit;
            min_price = (prices[i] > min_price) ? min_price : prices[i];
        }
        return max_profit;
    }
};

int main(){
    vector<int> test = {7,1,5,3,6,4};  
    Solution t;
    t.maxProfit(test);
   
}