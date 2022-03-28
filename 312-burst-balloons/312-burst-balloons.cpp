class Solution {
    vector<vector<int>> dp;
public:
    int solve(vector<int>& nums, int l, int r){
        if(r < l) return 0;
        if(r == l) return dp[l][r] = nums[l-1] * nums[r] * nums[r+1];
        if(dp[l][r] != -1) return dp[l][r];
        for(int k = l; k <= r; k++){
            dp[l][r] = max(dp[l][r], solve(nums, l, k - 1) + solve(nums, k + 1, r) + nums[k] * nums[l - 1] * nums[r + 1]);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int> padded;
        padded.push_back(1);
        for(auto & v: nums) padded.push_back(v);
        padded.push_back(1);
        int n = padded.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(padded, 1, n - 2);
    }
};