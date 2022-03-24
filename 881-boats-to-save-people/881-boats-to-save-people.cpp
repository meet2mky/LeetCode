class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int i = 0, r = people.size() - 1, ans = 0;
        while(i <= r){
            ans++;
            if( i != r && limit >= people[i] + people[r]){
                    i++;
            }
            r--;
        }
        return ans;
    }
};