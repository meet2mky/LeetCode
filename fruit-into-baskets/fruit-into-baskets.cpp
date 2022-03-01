class Solution {
public:
    int calculate(map<int,int>& mp){
        int ans = 0;
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
            ans += it->second;
        }
        return ans;
    }
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int n = fruits.size();
        int i = 0, j = 0, ans = 0;
        while(i < n || j < n){
            while(j < n && (mp.size() < 2 || mp.find(fruits[j]) != mp.end())){
                mp[fruits[j]]++;
                j++;
            }
            if(mp.size() < 2){
                break;
            }
            ans = max(ans, calculate(mp));
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
            i++;
        }
        ans = max(ans, calculate(mp));
        return ans;
    }
};