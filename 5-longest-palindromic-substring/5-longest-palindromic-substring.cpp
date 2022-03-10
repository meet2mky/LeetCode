class Solution {
public:
    // Manachars Algorithm
    vector<int> OddCentred(string s){
        int n = s.size();
        vector<int> d(n, 0);
        for(int i = 0, l = 0, r = -1; i < n; i++){
            int k = (i > r)? 1 : min(d[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i-k] == s[i+k])k++;
            d[i] =  k--;
            if(i + k > r){
                r = i + k;
                l = i - k;
            }
        }
        return d;
    }
    vector<int> EvenCentred(string s){
        int n = s.size();
        vector<int> d(n, 0);
        for(int i = 0, l = 0, r = -1; i < n; i++){
            int k = (i > r)? 0 : min(d[l + r - i + 1], r - i + 1);
            while(i - k - 1 >= 0 && i + k < n && s[i-k-1] == s[i+k])k++;
            d[i] =  k--;
            if(i + k > r){
                r = i + k;
                l = i - k - 1;
            }
        }
        return d;
    }
    string longestPalindrome(string s) {
        auto e = EvenCentred(s);
        auto o = OddCentred(s);
        int l = 0, r = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if((r - l + 1) < (2*o[i] - 1)){
                r = i + o[i] - 1;
                l = i - o[i] + 1;
            }
            if((r - l + 1) < (2*e[i])){
                r = i + e[i] - 1;
                l = i - e[i];
            }
        }
        return s.substr(l,r-l+1);
    }
};