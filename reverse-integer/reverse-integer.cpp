class Solution {
public:
    // 8     7
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool neg = false;
        if(x < 0) x = -x, neg = true;
        int reversed = 0;
        while(x > 0){
            if(reversed < INT_MAX/10 || (reversed == INT_MAX/10 && reversed % 10 <= 7)){
                reversed = reversed * 10 + (x % 10);
                x /= 10;
            }else{
                return 0;
            }
        }
        return neg ? -reversed : reversed;
    }
};