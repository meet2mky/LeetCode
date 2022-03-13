class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int best_buy = INT_MAX;
        for(auto & stock: prices){
            max_profit = max(max_profit, stock - best_buy);
            best_buy = min(best_buy, stock);
        }
        return max_profit;
    }
};