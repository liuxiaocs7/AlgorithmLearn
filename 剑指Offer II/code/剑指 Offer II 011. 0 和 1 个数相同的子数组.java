class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) nums[i] = -1;
        }

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0, res = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            res = Math.max(res, i - map.getOrDefault(sum, i));
            if(!map.containsKey(sum)) map.put(sum, i);
        }
        return res;
    }
}