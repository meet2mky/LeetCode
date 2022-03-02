class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = size(s);
        int tn = size(t);
        int si = 0;
        int ti = 0;
        while(si < sn && ti < tn){
            if(s[si] == t[ti]){
                si++;
            }
            ti++;
        }
        if(si == sn) return true;
        return false;
    }
};