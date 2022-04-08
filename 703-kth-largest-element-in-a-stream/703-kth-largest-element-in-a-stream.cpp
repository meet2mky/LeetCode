class KthLargest {
    multiset<int> S;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto x: nums){
            S.insert(x);
        }
    }
    int add(int val) {
        S.insert(val);
        while(S.size() > K){
            S.erase(S.begin());
        }
        return *S.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */