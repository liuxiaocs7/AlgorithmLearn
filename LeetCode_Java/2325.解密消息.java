/*
 * @lc app=leetcode.cn id=2325 lang=java
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character, Integer> map = new HashMap<>();
        int idx = 0;
        for (char c : key.toCharArray()) {
            if (c == ' ' || map.containsKey(c)) continue;
            map.put(c, idx++);
        }
        StringBuilder sb = new StringBuilder();
        for (char c : message.toCharArray()) {
            sb.append(c == ' ' ? ' ' : (char) (map.get(c) + 'a'));
        }
        return sb.toString();
    }
}
// @lc code=end

