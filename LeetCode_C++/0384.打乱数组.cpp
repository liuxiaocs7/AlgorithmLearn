/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
    vector<int> prev, cur;
    int n;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        for(auto &num : nums) {
            prev.push_back(num);
            cur.push_back(num);
        }
    }
    
    vector<int> reset() {
        for(int i = 0; i < n; i++) {
            cur[i] = prev[i];
        }
        return cur;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; i++) {
            int t = (rand() % n);
            swap(cur[i], cur[t]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

