class Solution {
public:
    int brokenCalc(int s, int e) {
        if(s >= e) return s-e;
        else{
            if(e&1){
                return 1 + brokenCalc(s, e+1);
            }else{
                return 1 + brokenCalc(s, e/2);
            }
        }
        return 0;
    }
};