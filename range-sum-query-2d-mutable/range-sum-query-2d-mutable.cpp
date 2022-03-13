class NumMatrix {
    vector<vector<int> > bit;
    int n, m;
    int lowbit(int x){
        return x & (-x);
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->n = matrix.size();
        this->m = matrix[0].size();
        bit = vector<vector<int>>(n + 1, vector<int>(m+1, 0));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                add(r,c, matrix[r][c]);
            }
        }
    }
    int query(int row, int col){
        int res = 0;
        for(int r = row + 1; r > 0; r -= lowbit(r)){
            for(int c = col + 1; c > 0; c-= lowbit(c)){
                res += bit[r][c];
            }
        }
        return res;
    }
    void add(int row, int col, int val){
        for(int r = row + 1; r <= n; r += lowbit(r)){
            for(int c = col + 1; c <= m; c += lowbit(c)){
                bit[r][c] += val;
            }
        }
    }
    void update(int row, int col, int val) {
        int cur = sumRegion(row,col,row,col);
        add(row,col,val-cur);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2,col2) - query(row2, col1 - 1) - query(row1 - 1, col2) + query(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */