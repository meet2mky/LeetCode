class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        auto num = [&](int i){
            return matrix[i/m][i%m];
        };
        int l = -1;
        int r = n*m;
        while(r-l > 1){
            int mid = (r+l)/2;
            if(num(mid) < target){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(r < n*m && num(r) == target) return true;
        return false;
    }
};