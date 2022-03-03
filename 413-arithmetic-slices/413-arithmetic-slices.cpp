class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
      int n = a.size();
      int now = 0;
      int ans = 0;
      for(int i = 2; i < n; i++){
        int d1 = a[i] - a[i-1];
        int d2 = a[i-1] - a[i-2];
        if(d1 == d2){
          now = 1 + now;
        }else{
          now = 0;
        }
        ans += now;
      }
      return ans;
    }
};