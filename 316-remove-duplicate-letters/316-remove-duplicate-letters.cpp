class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        vector<int> used(26,0);
        int n = s.size();
        for(int i = 0; i < n; i++) lastIndex[s[i]-'a'] = i;
        string res = "";
        for(int i = 0; i < n; i++){
            if(used[s[i]-'a'])continue;
            while(!res.empty() && s[i] < res.back() && lastIndex[res.back()-'a'] > i){
                used[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            used[res.back()-'a'] = 1;
        }
        return res;
    }
};