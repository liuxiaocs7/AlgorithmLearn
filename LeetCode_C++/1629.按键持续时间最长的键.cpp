/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size(), maxTime = releaseTimes[0];
        char res = keysPressed[0];
        for(int i = 1; i < n; i++) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if(t > maxTime) {
                maxTime = t;
                res = keysPressed[i]; 
            }
            if(t == maxTime) {
                res = max(res, keysPressed[i]);
            }
        }
        return res;
    }
};
// @lc code=end

