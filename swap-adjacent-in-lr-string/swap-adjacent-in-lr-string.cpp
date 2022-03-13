class Solution {
public:
    bool canTransform(string start, string end) {
        string rs, re;
        for(auto & ch: start) if( ch != 'X') rs += ch;
        for(auto & ch: end) if(ch != 'X') re += ch;
        if(re != rs) return false;
        int i = 0, j = 0, n = start.size();
        while(i < n && j < n){
            if(start[i] == 'X'){
                i++;
                continue;
            }else if(end[j] == 'X'){
                j++;
                continue;
            }else{
                if(start[i] == 'L'){
                    if(i < j) return false; // j <= i for good transform
                }
                if(start[i] == 'R'){
                    if(i > j) return false; // i <= j 
                }
                i++;
                j++;
            }
        }
        return true;
    }
};