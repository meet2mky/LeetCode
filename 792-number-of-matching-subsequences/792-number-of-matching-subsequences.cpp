class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int next[n][26];
        for(int i = n - 1; i >= 0; i--){
          for(int j = 0; j < 26; j++){
            if(i == n - 1){
              next[i][j] = (s[i]-'a' == j)? i : n;
            }else{
              next[i][j] = (s[i]-'a' == j)? i : next[i+1][j];
            }
          }
        }
        int ans = 0;
        for(auto & x: words){
            int i = 0;
            int j = 0;
            int m = x.size();
            while(j < m && i < n){
                if(s[i] == x[j]){
                  i++;
                  j++;
                }else{
                  i = next[i][x[j]-'a'];
                }
            }
            ans += (j == m);
        }
        return ans;
    }
};