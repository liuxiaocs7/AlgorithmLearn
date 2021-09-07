class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums.length >= 3) {
            Arrays.sort(nums);
            int i = 0;
            while(i < nums.length - 2) {
                twoSum(nums, i, res);
                int temp = nums[i];
                while(i < nums.length - 2 && temp == nums[i]) {
                    i++;
                }
            }
        }
        return res;
    }

    private void twoSum(int[] nums, int i, List<List<Integer>> res) {
        int j = i + 1;
        int k = nums.length - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0) {
                res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                // 保证使用不同的j
                int temp = nums[j];
                while(j < k && temp == nums[j]) j++;
            } else if(sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
}