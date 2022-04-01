class Solution {
public:
    void reverseString(vector<char>& s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            l++, r--;
        }
    }
    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size() - 1);
    }
};