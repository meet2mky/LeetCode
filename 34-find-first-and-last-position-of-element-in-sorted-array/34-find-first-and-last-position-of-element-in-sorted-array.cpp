class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> ans = {-1,-1};
        int n = size(nums);
        int l = -1, r = n; // l <= t... r > t 
        while(r-l > 1){
            int m = (r+l)/2;
            if(nums[m] > t){
                r = m;
            }else{
                l = m;
            }
        }
        if( l >= 0 && nums[l] == t) ans[1] = l;
        else return ans;
        l = -1, r = n; // l < t && r >= t
        while(r-l > 1){
            int m = (r+l)/2;
            if(nums[m] < t){
                l = m;
            }else{
                r = m;
            }
        }
        ans[0] = r;
        return ans;
    }
};