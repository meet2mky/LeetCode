class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0; // Something 
        int r = arr.size() - 2; // arr[r] > arr[r+1]; // 
        while(r - l > 1){
            int m = (r+l)/2;
            if(arr[m] > arr[m+1])r = m;
            else l= m;
        }
        return r;   
    }
};