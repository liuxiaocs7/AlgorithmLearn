class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Long> set = new TreeSet<>();
        for(int i = 0; i < nums.length; i++) {
            Long lower = set.floor((long)nums[i]);
            if(lower != null && lower >= (long)nums[i] - t) {
                return true;
            }

            Long upper = set.ceiling((long)nums[i]);
            if(upper != null && upper <= (long)nums[i] + t) {
                return true;
            }

            set.add((long)nums[i]);
            if(i >= k) {
                set.remove((long)nums[i - k]);
            }
        }
        return false;
    }
}