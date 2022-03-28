class Solution {
public:
    int search(vector<int>& nums, int l, int r, int x){
        while(r - l > 1){
            int m = l + (r-l)/2;
            if(nums[m] == x) return m;
            if(nums[m] < nums[r]){
                if(nums[m] <= x && x <= nums[r]){
                    l = m;
                }else{
                    r = m;
                }
            }else{
                if(nums[l] <= x && x <= nums[m]){
                    r = m;
                }else{
                    l = m;
                }
            }
        }
        if(nums[l] == x) return l;
        if(nums[r] == x) return r;
        return - 1;
    }
    int search(vector<int>& nums, int x) {
        return search(nums, 0, nums.size() - 1, x);
    }
};