class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n < 2) return 0;
        int dp[n];
        memset(dp,0,sizeof dp);
        int mx = 0;
        for(int i = 1; i < n; i++){
          if(s[i] == ')'){
            if(s[i-1] == '('){
              dp[i] = 2 + (i >= 2? dp[i-2]: 0);
            }else{
                // ()(())
                int l = i - dp[i-1] - 1;
                if(l >= 0 && s[l] == '('){
                  dp[i] = 2 + dp[i-1] + (l > 0 ? dp[l-1]: 0);  
                }
            }
          }
          mx = max(mx,dp[i]);
        }
      return mx;
    }
};