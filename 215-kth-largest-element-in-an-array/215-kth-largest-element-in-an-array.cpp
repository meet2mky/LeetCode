class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Method 1. Sort the array and return nums[n - k]; // O(nLogn), O(1)
        // Use PQ min heap // O(nlog(k)), O(k)
        // Use  QUICK SELECT SORT SORT K ELEMENTS
        //
        int l = 0, r = nums.size() - 1, kth;
        while(true){
            int idx = partition(nums,l,r);
            if(idx == k - 1){
                kth = nums[idx];
                break;
            }
            if(idx < k - 1){
                l = idx + 1;
            }
            else{
                r = idx - 1;
            }
        }
        for(auto & c: nums){
            cout << c << " ";
        }
        cout << endl;
        return kth;
    }
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int left  = l + 1;
        int right = r;
        while(right - left >= 0){
            if(nums[left] < pivot && nums[right] > pivot){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
            if(nums[left] >= pivot)left++;
            if(nums[right] <= pivot) right--;
        }
        swap(nums[l],nums[right]);
        return right;
    }
};