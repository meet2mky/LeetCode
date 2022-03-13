class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> candies(n, 1);
        for(int i = 0; i < n; i++){
            if(i && ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int j = n - 1; j >= 0; j--){
            if(j+ 1 < n && ratings[j] > ratings[j+1]){
                candies[j] = max(candies[j+1] + 1, candies[j]);
            }
        }
        return accumulate(begin(candies), end(candies), 0);
    }
};