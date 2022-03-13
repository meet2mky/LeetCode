class Fenwick{
    vector<int> bit;
    int n;
    int lowbit(int x){ return x & (-x);}
    public:
    Fenwick(int n){
        this->n = n;
        bit = vector<int>(n + 1, 0);
    }
    void add(int i, int val){
        for(int k = i + 1; k <= n; k += lowbit(k)){
            bit[k] += val;
        }
    }
    int query(int i){
        int res = 0;
        for(int k = i + 1; k > 0; k -= lowbit(k)){
            res += bit[k];
        }
        return res;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = 1e4 + 1e4 + 1;
        const int offset = 1e4;
        Fenwick fen(N);
        int n = nums.size();
        vector<int> cnt(n,0);
        for(int i =  n - 1; i >= 0; i--){
            cnt[i] = fen.query(nums[i] + offset - 1) ;
            fen.add(nums[i] + offset, 1);
        }
        return cnt;
    }
};