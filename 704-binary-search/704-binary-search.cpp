class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1;
        int r = n;
        while(r-l >1){
            int m = (r+l)/2;
            if(nums[m] < target) l = m;
            else r = m;
        }
        if(r < n && nums[r] == target) return r;
        return -1;
    }
};