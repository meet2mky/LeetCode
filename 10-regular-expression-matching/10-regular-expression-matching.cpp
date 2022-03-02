class Solution {
public:
    bool isMatch(string s, string p) {
      int n = s.size();
      int m = p.size();
      bool dp[n + 1][m + 1];
      memset(dp,false,sizeof dp);
      for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
              // i == 0 && j == 0 , true
              // i != 0 && j == 0 , false
              // i == 0 && j != 0 ,
              if(i == 0 && j == 0) dp[i][j] = true;
              if(i == 0 && j != 0 && p[j-1] == '*') dp[i][j] = dp[i][j-2];
            }else{
              if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
              }else{
                dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1];
              }
            }
        }
      }
      return dp[n][m];
    }
};