class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<int> best;
        int bestHH = -1,bestMM = -1;
        do{
            int hh = arr[0] * 10 + arr[1];
            int mm = arr[2] * 10 + arr[3];
            if(hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59){
                if(hh > bestHH || (hh == bestHH && mm > bestMM)){
                    best = arr;
                    bestHH = hh;
                    bestMM = mm;
                }
            }            
        }while(next_permutation(begin(arr),end(arr)));
        if(bestHH == -1) return "";
        string res = "00:00";
        res[0] = best[0] + '0';
        res[1] = best[1] + '0';
        res[3] = best[2] + '0';
        res[4] = best[3] + '0';
        return res;
    }
};