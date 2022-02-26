class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(size(nums1) > size(nums2)) swap(nums1,nums2);
        int N1 = size(nums1);
        int N2 = size(nums2);
        int l = 0, r = N1, l1, r1, l2, r2;
        int half = (N1 + N2 + 1)/2;
        auto good = [&](int m){
            l1 = (m == 0)? INT_MIN : nums1[m-1];
            r1 = (m == N1)? INT_MAX : nums1[m];
            l2 = (half - m == 0)? INT_MIN : nums2[half - m - 1];
            r2 = (half - m == N2)? INT_MAX : nums2[half - m];
            return make_pair(l1 <= r2 , l2 <= r1);
        };
        auto ans = [&](){
            if((N1 + N2)%2) return (double)max(l1,l2);
            return (double) (max(l1,l2) + min(r1,r2)) /2.0;
        };
        // AT m == 0: l1 <= r2 (sure) but l2 <= r1 (not sure)
        // AT m == N1: l1 <= r2 (not sure) but l2 <= r1 (sure)
        auto OK = make_pair(true,true);
        auto RV = good(r);
        if(RV == OK) return ans();
        auto LV = good(l);
        if(LV == OK) return ans();  
        while(r - l > 1){
            int m = (l + r) / 2;
            auto mv = good(m);
            if(mv == OK){
                return ans();                
            }else{
                if(mv == RV){
                    r = m;
                }else{
                    l = m;
                }
            }
        }
        return 0.0;
    }
};