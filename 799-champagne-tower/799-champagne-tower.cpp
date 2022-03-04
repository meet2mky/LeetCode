class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        const int N = 100;
        double water[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                water[i][j] = 0.0;
            }
        }
        water[0][0] = poured;
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j <= i; j++){
                double extra = max(0.0, water[i][j] - 1.0);
                water[i][j] -= extra;
                water[i+1][j] += extra/2.0;
                water[i+1][j+1] += extra/2.0;
            }
        }
        return min(1.0, water[query_row][query_glass]);
    }
};