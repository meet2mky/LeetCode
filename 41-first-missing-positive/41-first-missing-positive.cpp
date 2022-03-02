class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n = size(nums);
      for(int i = 0; i < n; i++){
        if(nums[i] < 1 || nums[i] > n) nums[i] = 0;
      }
      for(int i = 0; i < n; i++){
        int l = abs(nums[i]);
        if(l > 0 && l <= n){
          if(nums[l-1] == 0) nums[l-1] = - n - 1;
          if(nums[l-1] > 0) nums[l-1] = -nums[l-1];
        }
      }
      for(int i = 1; i <= n; i++){
        if(nums[i-1] >= 0)return i;
      }
      return n+1;
    }
};