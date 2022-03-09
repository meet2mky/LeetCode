class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> myStack;
        string transformed;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '('){
                myStack.push(c);
                transformed.push_back(c);
            }else if(c == ')'){
                if(!myStack.empty()){
                    myStack.pop();
                    transformed.push_back(c);
                }
            }
            else{
                transformed.push_back(c);
            }
        }
        swap(s,transformed);
        transformed = "";
        while(!myStack.empty()) myStack.pop();
        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];
            if(c == ')'){
                myStack.push(c);
                transformed.push_back(c);
            }else if(c == '('){
                if(!myStack.empty()){
                    myStack.pop();
                    transformed.push_back(c);
                }
            }
            else{
                transformed.push_back(c);
            }
        }
        swap(s,transformed);
        reverse(begin(s),end(s));
        return s;
    }
};