enum DIR{
    LEFT,
    RIGHT,
    UP,
    DOWN
};


int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};

DIR turnRight[4]={UP,DOWN,RIGHT,LEFT};


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int counter=1;
        int r=0;
        int c=0;
        auto safe=[&](int r,int c){
            return r>=0 && c>=0 && r<n && c<n && res[r][c]==0;
        };
        DIR cd=RIGHT;
        while(counter<=n*n){
            res[r][c]=counter++;
            if(!safe(r+dr[cd],c+dc[cd])){
                cd=turnRight[cd];
            }
            r+=dr[cd];
            c+=dc[cd];
        }
        return res;
    }
};