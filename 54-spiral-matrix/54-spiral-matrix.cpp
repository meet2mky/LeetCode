class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int dir = 0;
        int r = 0, c = 0;
        auto safe = [&](int r_, int c_){
            return (r_ >= 0 && r_ < rows && c_ >= 0 && c_ < cols) && (matrix[r_][c_] != 404);
        };
        while(res.size() < rows*cols){
            if(!safe(r,c)){
                r -= dr[dir];
                c -= dc[dir];
                dir = (dir + 1) %4;
                r += dr[dir];
                c += dc[dir];
            }
            res.push_back(matrix[r][c]);
            matrix[r][c] = 404;
            r += dr[dir];
            c += dc[dir];
        }
        return res;
    }
};