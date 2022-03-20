class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> cnt(7,0);
        for(int i = 0; i < n; i++){
            if(tops[i] == bottoms[i]) cnt[tops[i]]++;
            else cnt[tops[i]]++, cnt[bottoms[i]]++;
        }
        int choose = -1;
        for(int i = 1; i < 7; i++){
            if(cnt[i] >= n) choose = i;
        }
        if(choose == -1) return -1;
        int scoreUp = 0;
        int scoreDown = 0;
        for(int i = 0; i < n; i++){
            if(tops[i] != choose) scoreUp++;
            if(bottoms[i] != choose) scoreDown++;
        }
        return min(scoreUp, scoreDown);
    }
};