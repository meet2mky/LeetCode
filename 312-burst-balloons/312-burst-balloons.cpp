class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l = 1; l <= n; l++){
            for(int s = 1; s + l < n; s++){
                int e = s + l - 1;
                for(int lst = s; lst <= e; lst++){
                    dp[s][e] = max(dp[s][e], dp[s][lst-1] + dp[lst+1][e] + 
                                  nums[lst] * nums[s-1] * nums[e+1]);
                }
            }
        }
        return dp[1][n-2];
    }
};