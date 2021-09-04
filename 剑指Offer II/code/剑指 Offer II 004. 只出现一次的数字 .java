class Solution {
    public int singleNumber(int[] nums) {
        int[] bitSums = new int[32];
        for(int num : nums) {
            for(int i = 0; i < 32; i++) {
                bitSums[i] += ((num >> (31 - i)) & 1);
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = (res << 1) + bitSums[i] % 3;
        }
        return res;
    }
}