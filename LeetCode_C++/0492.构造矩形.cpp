/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); ; i--) {
            if(area % i == 0) return {area / i, i};
        }
        return {};
    }
};
// @lc code=end

