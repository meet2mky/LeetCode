/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int find_ans(string& a, string& b){
        int cnt = 0;
        for(int i = 0; i < 6; i++) cnt += (a[i] == b[i]);
        return cnt;
    }
    int canEleminate(string & word, vector<string>& words){
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            ans += (find_ans(word, words[i]) != 0);
        }
        return ans;
    };
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<string> good, bad;
        for(auto & word: words) good.push_back(word);
        while(good.size() > 0){
            int maxE = 0, i = 0;
            for(int i = 0; i < good.size(); i++){
                int nowE = canEleminate(good[i], good);
                if(nowE > maxE){
                    maxE = nowE;
                    i = i;
                }
            }
            swap(good[i], good[good.size()-1]);
            auto secret = good.back();
            good.pop_back();
            int secret_ans = master.guess(secret);
            if(secret_ans == 6) return;
            bad.clear();
            for(auto & x: good){
                if(find_ans(secret,x) == secret_ans) bad.push_back(x);
            }
            swap(good,bad);
        }
    }
};