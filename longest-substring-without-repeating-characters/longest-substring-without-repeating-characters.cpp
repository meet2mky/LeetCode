class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> nonRepeating;
        int i = 0, j = 0, ans = 0, n = (int)s.size();
        while(i < n || j < n){
            while(j < n && nonRepeating.find(s[j]) == nonRepeating.end()){
                nonRepeating.insert(s[j]);
                j++;
            }
            ans = max(ans, (int)nonRepeating.size());
            nonRepeating.erase(s[i]);
            i++;
        }
        return ans;
    }
};