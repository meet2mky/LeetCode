class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = size(arr);
        map<int,int> index;
        vector<bool> odd(n,false), even(n,false);
        odd[n-1] = even[n-1] = true;
        index[arr[n-1]] = n-1;
        int res = 1;
        for(int i = n - 2; i >= 0; i--){
            auto upper =  index.upper_bound(arr[i]); //>
            auto lower =  index.lower_bound(arr[i]); //>= 
            if(upper != index.begin()){
                upper--;
                even[i] = odd[(*upper).second]; 
            }
            if(lower != index.end()){
                odd[i] = even[(*lower).second];
            }
            res += odd[i];
            index[arr[i]] = i;
        }
        return res;
    }
};