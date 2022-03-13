class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1, mn = 1, nmx, nmn, ans = INT_MIN, n = size(nums);
        for(int i = 0; i < n; i++){
            nmx = max(nums[i], max(nums[i]*mx, nums[i]*mn));
            nmn = min(nums[i], min(nums[i]*mx, nums[i]*mn));
            ans = max(nmx,ans);
            mx = nmx;
            mn = nmn;
        }
        return ans;
    }
};