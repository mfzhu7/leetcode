class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_index = {int(prices.size() - 1)};
        int index = prices.size() - 2;
        while(index >= 0){
            if (prices[index] > prices[*max_index.begin()]){
                max_index.emplace(max_index.begin(), index);
                index = index - 1;
            } else {
                max_index.emplace(max_index.begin(), *max_index.begin());
                index = index - 1;
            }
        }
        int res_index = max_index[0];
        int max_profit = prices[res_index] - prices[0];
        for (int i = 1; i <= prices.size() - 1; i ++){
            max_profit = (prices[max_index[i]] - prices[i]) > max_profit ? (prices[max_index[i]] - prices[i]) : max_profit;
        }
        return max_profit;

    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i <= prices.size() - 1; i++){
            max_profit = ((prices[i] - min_price) > max_profit) ? (prices[i] - min_price): max_profit;
            min_price = prices[i] > min_price ? min_price : prices[i];
        }
        return max_profit;
    }
};