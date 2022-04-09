class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto x: nums) ump[x]++;
        int n = nums.size();
        vector<vector<int>> arr(n + 1);
        for(auto x: ump) arr[x.second].push_back(x.first);
        vector<int> res;
        for(int i = n; i >= 0 && k; i--){
            for(auto g: arr[i]){
                res.push_back(g);
                k--;
                if(k==0)break;
            }
        }
        return res;
    }
};