/*
 * @lc app=leetcode.cn id=929 lang=java
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for(String s : emails) {
            int n = s.length(), i = 0;
            StringBuilder sb = new StringBuilder();
            boolean ok = true;
            while(i < n) {
                char c = s.charAt(i);
                if(c == '@') break;
                if(c == '+') ok = false;
                if(c == '.' && ++i > 0) continue;
                if(ok) sb.append(c);
                i++;
            }
            set.add(sb.append(s.substring(i)).toString());
        }
        return set.size();
    }
}
// @lc code=end

