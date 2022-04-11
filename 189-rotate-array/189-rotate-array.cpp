class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int cycles=__gcd(k,n);
        for(int i=0;i<cycles;i++){
            int j=(i+k)%n;
            int prev=nums[i];
            while(j!=i){
                int curr=nums[j];
                nums[j]=prev;
                prev=curr;
                j=(j+k)%n;
            }
            nums[i]=prev;
        }
    }
};