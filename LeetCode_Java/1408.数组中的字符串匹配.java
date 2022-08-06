/*
 * @lc app=leetcode.cn id=1408 lang=java
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> res = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (words[j].indexOf(words[i]) >= 0) {
                    res.add(words[i]);
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end

