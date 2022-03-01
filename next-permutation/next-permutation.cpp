class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
      int t = nums[i];
      nums[i] = nums[j];
      nums[j] = t;
    }
    void reverse(vector<int>& nums, int i, int j){
      while(i < j){
        swap(nums, i, j);
        i++;
        j--;
      }
    }
    void nextPermutation(vector<int>& nums) {
        int toSwap = -1;
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--){
          if(nums[i] < nums[i+1]){
            toSwap = i;
            break;
          }
        }
        if(toSwap != -1){
          for(int fromSwap = n - 1; fromSwap > toSwap; fromSwap--){
            if(nums[fromSwap] > nums[toSwap]){
              swap(nums, fromSwap, toSwap);
              break;
            }
          }
        }
        reverse(nums,toSwap + 1, n - 1);
    }
};