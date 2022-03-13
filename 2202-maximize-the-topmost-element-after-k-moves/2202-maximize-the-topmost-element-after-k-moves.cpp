class Solution {
public:
    /*
    [3,2,5,4,0,6], k = 3
    rem = 3
    rem = 2
    rem = 5
    */
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k % 2 == 1){
            return -1; // CASE EDGE
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(k >= i && (k- i) != 1)ans = max(ans, nums[i]);
        return ans;
    }
};