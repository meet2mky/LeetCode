class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int h = nums[0];
        int t = nums[0];
        while(true){
            h = nums[h];
            t = nums[nums[t]];
            if(h == t) break;
        }
        h = nums[0];
        while(h != t){ h = nums[h], t = nums[t];}
        return h;
    }
};