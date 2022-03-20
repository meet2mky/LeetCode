class Solution {
    public int[] nextGreaterForAll(int [] nums){
        // O(n)
        int[] nextGreater = new int[nums.length];
        Stack<Integer> stack = new Stack<Integer>();
        for(int i = 0; i < nums.length; i++){
            while(!stack.isEmpty() && nums[i] > nums[stack.peek()]){
                nextGreater[stack.peek()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.isEmpty()){
            nextGreater[stack.peek()] = -1;
            stack.pop();
        }
        return nextGreater;
    }
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> indexInNums2 = new HashMap<Integer,Integer>();
        for(int i = 0; i < nums2.length; i++){
            indexInNums2.put(nums2[i], i);
        }
        int[] ans = new int[nums1.length];
        int [] nextGreater = nextGreaterForAll(nums2);
        for(int i = 0; i < nums1.length; i++){
            int index = indexInNums2.get(nums1[i]);
            ans[i] = nextGreater[index];
        }
        return ans;
    }
}