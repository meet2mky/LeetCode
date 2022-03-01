class Solution {
public:
    string multiply(string num1, string num2) {
      int len1 = num1.size();
      int len2 = num2.size();
      vector<int> cnt(len1 + len2, 0);
      for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            cnt[i+j] += (num1[len1 - 1 - i]-'0')*(num2[len2 -1 - j]-'0');
        }
      }
      string res;
      for(int i = 0; i < len1 + len2; i++){
        res.push_back((char)(cnt[i] % 10 + '0'));
        if(cnt[i]/10){
          cnt[i+1] += cnt[i]/10;
        }
      }
      while(res.size() > 1 && res.back() == '0') res.pop_back();
      reverse(begin(res),end(res));
      return res;
    }
};