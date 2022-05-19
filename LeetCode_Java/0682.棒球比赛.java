/*
 * @lc app=leetcode.cn id=682 lang=java
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {

    public int calPoints(String[] ops) {
        List<Integer> list = new ArrayList<>();

        int sum = 0;
        for(String op : ops) {
            char c = op.charAt(0);
            int n = list.size();
            if(c == 'C') {
                sum -= list.get(n - 1);
                list.remove(n - 1);
            } else if(c == 'D') {
                list.add(list.get(n - 1) * 2);
                sum += list.get(list.size() - 1);
            } else if(c == '+') {
                int a = list.get(n - 2);
                int b = list.get(n - 1);
                list.add(a + b);
                sum += a + b;
            } else {
                int num = Integer.parseInt(op);
                sum += num;
                list.add(num);
            }
        }
        return sum;
    }
}
// @lc code=end

