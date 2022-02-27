class Solution {
public:
    bool goodSplit(vector<int>& pref, vector<int>& suf){
        int prefCnt = 0, sufCnt = 0;
        for(int i = 0; i < (int)pref.size(); i++){
            if(pref[i] != 0) prefCnt++;
            if(suf[i] != 0) sufCnt++;
        }
        return sufCnt == prefCnt;
    }
    int numSplits(string s) {
        vector<int> pref(26,0), suf(26,0);
        for(auto & ch: s){
            suf[ch-'a']++;
        }
        int ans = 0;
        for(int i = 0; i < (int)s.size() - 1; i++){
            pref[s[i]-'a']++;
            suf[s[i]-'a']--;
            ans += goodSplit(pref, suf);
        }
        return ans;
    }
};