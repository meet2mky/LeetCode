class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] - a[1] < b[0] - b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs),end(costs),cmp);
        int n = costs.size();
        n/=2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += costs[i][0];
            ans += costs[n+i][1];
        }
        return ans;
    }
};