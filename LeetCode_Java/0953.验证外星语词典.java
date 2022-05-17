/*
 * @lc app=leetcode.cn id=953 lang=java
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < order.length(); i++) {
            map.put(order.charAt(i), i);
        }

        int n = words.length;
        for(int i = 1; i < n; i++) {
            String prev = words[i - 1];
            String cur = words[i];
            if(!check(prev, cur, map)) return false;
        }
        return true;
    }

    boolean check(String prev, String cur, Map<Character, Integer> map) {
        int m = prev.length(), n = cur.length();
        int idx = 0; 
        while(idx < m && idx < n) {
            char c1 = prev.charAt(idx);
            char c2 = cur.charAt(idx);
            if(c1 != c2) return map.get(c1) < map.get(c2);
            idx++;
        }
        return idx < m ? false : true;
    }
}
// @lc code=end

