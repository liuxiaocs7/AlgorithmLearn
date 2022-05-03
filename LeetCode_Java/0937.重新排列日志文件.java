/*
 * @lc app=leetcode.cn id=937 lang=java
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution {

    class Log {
        int type, idx;
        String ori, sign, content;

        Log(String s, int _idx) {
            ori = s;
            idx = _idx;
            int i = 0;
            while(i < s.length() && s.charAt(i) != ' ') i++;
            sign = s.substring(0, i);
            content = s.substring(i + 1);
            type = Character.isDigit(content.charAt(0)) ? 1 : 0;
        }
    }

    public String[] reorderLogFiles(String[] logs) {
        List<Log> list = new ArrayList<>();
        int n = logs.length;
        for(int i = 0; i < n; i++) {
            list.add(new Log(logs[i], i));
        }
        Collections.sort(list, (a, b) -> {
            if(a.type != b.type) return a.type - b.type;
            if(a.type == 1) return a.idx - b.idx;
            return !a.content.equals(b.content) ? a.content.compareTo(b.content) : a.sign.compareTo(b.sign);
        });
        String[] res = new String[n];
        for(int i = 0; i < n; i++) {
            res[i] = list.get(i).ori;
        }
        return res;
    }
}
// @lc code=end

