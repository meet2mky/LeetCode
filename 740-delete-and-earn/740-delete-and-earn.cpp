class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 1e4 + 1;
        vector<int> val(N,0);
        for(auto & v: nums){
            val[v] += v;
        }
        vector<int> dp(N, 0);
        dp[1] = val[1];
        for(int i = 2; i < N; i++){
            dp[i] = max(val[i] + dp[i-2], dp[i-1]);
        }
        return max(dp[N-1], dp[N-2]);
    }
};