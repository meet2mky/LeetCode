class Solution {
public:
    bool validPalindrome(const string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(validPalindrome(s,0,s.size() - 1)) return true;
        int l = 0, r = s.size() - 1;
        while(s[l] == s[r]){
            l++;
            r--;
        }
        if(validPalindrome(s, l + 1, r) || validPalindrome(s, l, r - 1)) return true;
        return false;
    }
};