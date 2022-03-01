class Solution {
public:
    char toUpper(char ch){
        if(ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A';
        return ch;
    }
    string licenseKeyFormatting(string s, int k) {
        string res;
        for(int i = size(s) - 1; i >= 0; i--){
            if(s[i] == '-')continue;
            res.push_back(toUpper(s[i]));
            if((size(res) + 1)%(k+1) == 0){
                res.push_back('-');
            }
        }
        if(res.back() == '-')res.pop_back();
        reverse(begin(res),end(res));
        return res;

    }
};