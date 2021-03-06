class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> score;
        for(auto ch: s){
            if(ch == '('){
                score.push(0);
            }else{

                if(score.top() == 0){
                    score.pop();
                    score.push(1);
                }else{
                    int v = 0;
                    while(score.top() != 0){
                        v += score.top();
                        score.pop();
                    }
                    score.pop();
                    score.push(2*v);
                }
            }
        }
        int ans = 0;
        while(score.size()){
            ans += score.top();
            score.pop();
        }
        return ans;
    }
};