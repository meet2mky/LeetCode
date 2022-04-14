class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        int r = 0, c = 0;
        int dir = 0;
        int val = 1;
        vector<vector<int> > ans(n,vector<int>(n,0));
        auto safe = [&](int i , int j){
            if(i < 0 || i >= n || j < 0 || j >= n || ans[i][j] > 0) return false;
            return true;
        };
        while(val  <= (n * n)){
            ans[r][c] = val++;
            r += dr[dir];
            c += dc[dir];
            if(!safe(r,c)){
                r-=dr[dir];
                c-=dc[dir];
                dir = (dir + 1) % 4;
                r += dr[dir];
                c += dc[dir];
            }
        }
        return ans;
    }
};