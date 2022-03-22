class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        while((n-1)*26 >= k-1){
            res.push_back('a');
            n--;
            k--;
        }
        if(k % 26 != 0){
            res.push_back('a'  - 1 + k % 26);
            k -= k %26;
        }
        while(k){
            res.push_back('z');
            k-=26;
        }
        return res;
    }
    
};