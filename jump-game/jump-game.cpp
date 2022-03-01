class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can = nums[0], n = size(nums);
        for(int i = 1; i < n; i++){
            if(i <= can) can = max(can, nums[i] + i);
            else break;
        }
        return can >= n-1;
    }
};