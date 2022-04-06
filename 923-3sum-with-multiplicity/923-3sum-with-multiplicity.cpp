class Solution {
public:
    
    int threeSumMulti(vector<int>& a, int y) {
        int MOD = 1e9 + 7;
        int n = a.size();
        vector<int> mp(101, 0);
        int ans = 0;
        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int need = y - a[j] - a[k];
                if(need >= 0 && need <= 100){
                    ans = (ans + mp[need]) % MOD;
                }
            }
            mp[a[j]]++;
        }
        return ans;
    }
};