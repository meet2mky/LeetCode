class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = size(board);
        int n = size(board[0]);
        auto res = board;
        vector<int> dx = {0,0,1,-1,1,-1,1,-1};
        vector<int> dy = {-1,1,0,0,1,-1,-1,1};
        auto fun = [&](int i, int j){
          if(i < 0 || i >= m || j < 0 || j >= n) return 0;
            return board[i][j];
        };
        auto liveCells = [&](int i, int j){
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                cnt += fun(i + dx[k], j + dy[k]);
            }
            return cnt;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]){
                    if(liveCells(i,j) < 2){
                     res[i][j] = 0;   
                    }else if(liveCells(i,j) < 4){
                        res[i][j] = 1;
                    }else{
                        res[i][j] = 0;
                    }
                }else{
                    if(liveCells(i,j) == 3){
                        res[i][j] = 1;
                    }
                }
            }
        }
        board = res;
    }
};