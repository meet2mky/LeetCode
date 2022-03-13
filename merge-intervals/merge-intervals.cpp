class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto & intv: intervals){
            if(ans.empty() || ans.back()[1] < intv[0]){
                ans.push_back(intv);
            }else{
                ans.back()[1] = max(ans.back()[1], intv[1]);
            }
        }
        return ans;
        
    }
};