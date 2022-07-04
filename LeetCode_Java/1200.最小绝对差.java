/*
 * @lc app=leetcode.cn id=1200 lang=java
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minV = Integer.MAX_VALUE;
        int n = arr.length;
        List<List<Integer>> lst = new ArrayList<>();
        for(int i = 0; i < n - 1; i++) {
            int t = arr[i + 1] - arr[i];
            if(t < minV) {
                lst.clear();
                minV = t;
            }
            if(t <= minV) {
                lst.add(Arrays.asList(arr[i], arr[i + 1]));
            }
        }
        return lst;
    }
}
// @lc code=end

