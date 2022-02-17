/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i = 0; i < len; i++) {
            if(!flowerbed[i] && (!i || !flowerbed[i - 1]) && (i == len - 1 || !flowerbed[i + 1])) {
                n--;
                flowerbed[i] = 1;
            }
            if(n <= 0) return true;
        }
        return n <= 0;
    }
};
// @lc code=end

