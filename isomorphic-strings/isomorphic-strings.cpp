class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> forward;
        unordered_map<char, char> backward;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(forward.find(s[i]) == forward.end()) forward[s[i]] = t[i];
            if(backward.find(t[i]) == backward.end()) backward[t[i]] = s[i];
            if(forward[s[i]] != t[i] || backward[t[i]] != s[i]) return false;
        }
        return true;
    }
};