/*
 * @lc app=leetcode.cn id=763 lang=java
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] right = new int[26];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            right[s.charAt(i) - 'a'] = i;
        }

        List<Integer> res = new ArrayList<>();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            r = Math.max(r, right[s.charAt(i) - 'a']);
            if (i == r) {
                res.add(r - l + 1);
                l = r = i + 1;
            }
        }
        return res;
    }
}
// @lc code=end

