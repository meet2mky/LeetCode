class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m*n);
        auto res = grid;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int loc = ((i*n + j) + k) %(m*n);
                res[loc / n][loc % n] = grid[i][j];
            }
        }
        return res;
    }
};