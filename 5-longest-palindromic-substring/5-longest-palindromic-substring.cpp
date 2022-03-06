class Solution {
    vector<int> D1(string s){
        int n = s.size();
        vector<int> d1(n,0);
        // Manacher's algorithm--
        // {l,r} == {0,-1}
        // i > r, k = 1
        // i <= r, {l......i......r} ==> l + r - i ==>k <= d1[l+r-i],  k <= r-i+1;
        for(int i = 0, l = 0,r = -1; i < n; i++){
            int k = (i > r)? 1: min(d1[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i-k] == s[i+k])k++;
            d1[i] = k--;
            if(r < i+k){
                r = i+k;
                l = i-k;
            }
        }
        return d1;
    }
    vector<int> D2(string s){
        int n = s.size();
        vector<int> d2(n,0);
        // Manacher's algorithm--
        // {l,r} == {0,-1}
        // i > r, k = 0
        //    .
        // L..I..I..R
        // 0123456789
        // ABCDEEDCBA ==> I` = L + R - I
        // 
        // EDCBA
        // i <= r, {l.........i....r} ==> l + r - i + 1 ==>k <= d1[l+r-i + 1],  k <= r - i + 1;
        for(int i = 0,l = 0,r = -1; i < n; i++){
            int k = (i > r)? 0: min(d2[l+r-i+1],r-i+1);
            while(i - k - 1 >= 0 && i + k < n && s[i-k-1] == s[i+k])k++;
            d2[i] = k--;
            if(r < i+k){
                r = i+k;
                l = i-k-1;
            }
        }
        return d2;
    }
public:
    string longestPalindrome(string s) {
        vector<int> d1 = D1(s);
        vector<int> d2 = D2(s);
        int p1=0,p2=0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(d1[p1] < d1[i])p1 = i;
            if(d2[p2] < d2[i])p2 = i;
        }
        if(d1[p1]*2 - 1 >= d2[p2]*2){
            return s.substr(p1 - d1[p1] + 1,d1[p1]*2-1);
        }
        return s.substr(p2-d2[p2],d2[p2]*2);
    }
};