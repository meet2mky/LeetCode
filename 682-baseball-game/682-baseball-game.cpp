class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for(auto & token: ops){
            if(isdigit(token.back())){
                st.push_back(stoi(token));
            }else if(token == "+"){
                st.push_back(st[st.size()-1] + st[st.size()-2]);
            }else if(token == "D"){
                st.push_back(st.back() * 2);
            }else{
                st.pop_back();
            }
        }
        return accumulate(begin(st), end(st), 0);
    }
};