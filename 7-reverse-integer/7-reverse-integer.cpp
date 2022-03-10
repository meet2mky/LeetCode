class Solution {
public:
    
    int reverse(int x) {
        int sign = 1, res = 0;
        if(x < 0){
            if(x == INT_MIN) return 0;
            x = -x;
            sign = -1;
        }
        while(x){
            int d = x%10;
            if(res < INT_MAX/10 || (res == INT_MAX/10 && d <= 7)) res = res * 10 + d;
            else return 0;
            x/=10;
        }
        return sign*res;
    }
};