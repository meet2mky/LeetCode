class Solution {
public:
    bool isStrobogrammatic(string num) {
        int mp[10] = {-1};
        mp[0] = 0;
        mp[1] = 1;
        mp[6] = 9;
        mp[9] = 6;
        mp[8] = 8;
        int l = 0, r = num.size() - 1;
        while(r - l >= 0){
            if(mp[num[l]-'0'] != num[r]-'0') return false;
            l++;
            r--;
        }
        return true;
    }
};