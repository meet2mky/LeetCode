class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> ust;
        for(auto & jewel: jewels){
            ust.insert(jewel);
        }
        int countJewels = 0;
        for(auto & stone: stones){
            if(ust.find(stone) != ust.end()) countJewels++;
        }
        return countJewels;
    }
};