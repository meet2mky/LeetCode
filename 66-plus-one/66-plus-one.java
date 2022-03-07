class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for(int i = digits.length - 1; i >= 0; i--){
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
            if(carry == 0) return digits;
        }
        int [] ans = new int[digits.length + 1];
        ans[0] = 1;
        return ans;
    }
}