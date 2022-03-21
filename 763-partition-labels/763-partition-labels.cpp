class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> f(26,0);
        for(auto ch: s) f[ch-'a']++;
        unordered_map<char, int> curr;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(curr.size() == 0){
                ans.push_back(0);
            }
            if(curr.find(s[i]) == curr.end()){
                curr[s[i]] = f[s[i]-'a'];
            }
            ans.back() += 1;
            curr[s[i]]--;
            if(curr[s[i]] == 0) curr.erase(s[i]);
        }
        return ans;
    }
};