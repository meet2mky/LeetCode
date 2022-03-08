class Solution {
public:
    char opening(char ch){
        if(ch == ')') return '(';
        if(ch == '}') return '{';
        if(ch == ']') return '[';
        return '\0';
    }
    bool isValid(string s) {
        stack<char> S;
        for(auto c: s){
            if(c == '(' || c == '{' || c == '['){
                S.push(c);
            }else{
                if(S.empty() || S.top() != opening(c))return false;
                S.pop();
            }
        }
        return S.size() == 0;
    }
};