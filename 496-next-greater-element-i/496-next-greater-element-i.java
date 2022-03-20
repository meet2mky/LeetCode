class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> indexInNums2 = new HashMap<Integer,Integer>();
        for(int i = 0; i < nums2.length; i++){
            indexInNums2.put(nums2[i], i);
        }
        int[] ans = new int[nums1.length];
        for(int i = 0; i < nums1.length; i++){
            int index = indexInNums2.get(nums1[i]);
            Boolean solved = false;
            for(int j = index + 1; j < nums2.length; j++){
                if(nums2[j] > nums2[index]){
                    ans[i] = nums2[j];
                    solved = true;
                    break;
                }
            }
            if(!solved) ans[i] = -1;
        }
        return ans;
    }
}