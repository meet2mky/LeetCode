class Solution {
    map<char,int> roman;
public:
    Solution(){
        roman.clear();
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
    }
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n;){
            int curr = roman[s[i]];
            int next = (i + 1 < n) ? roman[s[i+1]]:0;
            if(next > curr){
                res += next - curr;
                i++;
            }else{
                res += curr;
            }
            i++; 
        }
        return res;
    }
    /*
    M = 1000;
    CM = 900
    XC = 90
    IV = 4
    */
};