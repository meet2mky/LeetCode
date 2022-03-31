class Solution {
public:
    bool pos(int maxSum, const vector<int>& nums, int parts){
        int currSum = 0;
        int currParts = 1;
        for(auto num: nums){
            if(num > maxSum) return false;
            else if(num + currSum <= maxSum) currSum += num;
            else{
                currSum = num;
                currParts++;
            }
        }
        return currParts <= parts;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = -1, r = 1e9;
        while(r - l > 1){
            int mid = l + (r-l)/2;
            if(pos(mid, nums, m)){
                r = mid;
            }else{
                l = mid;
            }
        }
        return r;
    }
};