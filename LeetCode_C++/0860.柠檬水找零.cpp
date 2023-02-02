/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto x : bills) {
            if (x == 5) five++;
            else if (x == 10) {
                if (!five) return false;
                five--, ten++;
            } else {
                if (five && ten) five--, ten--;
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

