class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit(n + 1, 0);
        for(int i = 1; i <= n; i++){
            bit[i] = (i&1) + bit[i/2];
        }
        return bit;
    }
};