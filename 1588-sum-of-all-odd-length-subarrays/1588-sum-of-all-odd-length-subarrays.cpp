class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int prefixSum[n];
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = arr[i] + prefixSum[i-1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j <n;j++){
                if((j-i + 1)%2){
                    ans += prefixSum[j];
                    if(i-1 >= 0){
                        ans -= prefixSum[i-1];
                    }
                }
            }
        }
        return ans;
    }
};