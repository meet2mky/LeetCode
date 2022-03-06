class Solution {
public:
    int countOrders(int n) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            // i - 1, puts, i - 1 + i - 1 , i - 1 + 
            dp[i] = dp[i-1]*((2*i - 1) *i);
            dp[i] %= MOD;
        }
        return dp[n];
    }
};