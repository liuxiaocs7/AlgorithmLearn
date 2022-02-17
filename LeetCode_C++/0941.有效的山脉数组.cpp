/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        while(i < n - 1 && A[i] < A[i + 1]) i++;
        while(j > 0 && A[j] < A[j - 1]) j--;
        return i > 0 && i == j && j < n - 1;
    }
};
// @lc code=end

