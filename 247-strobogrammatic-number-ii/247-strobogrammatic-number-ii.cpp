class Solution {
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'}, 
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
public:
    vector<string> find(int curr, int n){
        if(curr == 0) return {""};
        else if( curr == 1) return {"0", "1","8"};
        auto prev = find(curr-2, n);
        vector<string> now;
        for(auto number: prev){
            for(auto reversiblePair: reversiblePairs){
                if(reversiblePair[0] != '0' || curr != n){
                    now.push_back(reversiblePair[0] + number + reversiblePair[1]);
                }
            }
        }
        return now;
    }
    vector<string> findStrobogrammatic(int n) {
        return find(n,n);
    }
};