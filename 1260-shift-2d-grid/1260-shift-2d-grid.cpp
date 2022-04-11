class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m_ = grid.size();
        int n_ = grid[0].size();
        int n = n_*m_;
        k=k%n;
        auto get = [&](int i){
            return grid[i/n_][i%n_];
        };
        auto set = [&](int i, int val){
            grid[i/n_][i%n_] = val;
        };
        int cycles=__gcd(k,n);
        for(int i=0;i<cycles;i++){
            int j=(i+k)%n;
            int prev=get(i);
            while(j!=i){
                int curr=get(j);
                set(j,prev);
                prev=curr;
                j=(j+k)%n;
            }
            set(i,prev);
        }
        return grid;
    }
};