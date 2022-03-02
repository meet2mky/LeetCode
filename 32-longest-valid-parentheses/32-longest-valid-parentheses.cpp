class Solution {
public:
    int longestValidParentheses(string S) {
        stack<int> s;
        s.push(-1);
        int ans = 0;
        for(int i = 0; i < (int)S.size(); i++){
          char c = S[i];
          if(c == '('){
            s.push(i);
          }else{
            if(!s.empty()){
              s.pop();
            }
            if(s.empty()){
              s.push(i);
            }
            ans = max(ans,i - s.top());
          }
        }
      return ans;
    }
};