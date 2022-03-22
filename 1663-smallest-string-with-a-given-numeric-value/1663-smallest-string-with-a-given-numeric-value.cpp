class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        while(n > 0){
            if(n *26 == k){
                res += string(n,'z');
                n = 0;
            }else if((n - 1)* 26  >= k - 1){
                res += "a";
                n--;
                k--;
            }else{
                res.push_back( 'a' + (k-1) - (n-1)*26);
                n--;
                k-= res.back() - 'a' + 1;
            }
        }
        return res;
    }
    
};