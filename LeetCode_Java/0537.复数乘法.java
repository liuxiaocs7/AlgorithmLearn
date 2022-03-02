/*
 * @lc app=leetcode.cn id=537 lang=java
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        String[] num1Str = num1.split("\\+");
        String[] num2Str = num2.split("\\+");
        int num1Real = Integer.parseInt(num1Str[0]);
        int num2Real = Integer.parseInt(num2Str[0]);
        int num1Fake = Integer.parseInt(num1Str[1].substring(0, num1Str[1].length() - 1));
        int num2Fake = Integer.parseInt(num2Str[1].substring(0, num2Str[1].length() - 1));
        int resReal = num1Real * num2Real - num1Fake * num2Fake;
        int resFake = num1Real * num2Fake + num1Fake * num2Real;
        return "" + resReal + "+" + resFake + "i";
    }
}
// @lc code=end

