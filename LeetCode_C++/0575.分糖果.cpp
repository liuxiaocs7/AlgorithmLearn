/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for(auto &candy : candyType) {
            if(!st.count(candy)) st.insert(candy);
        }
        if(n / 2 > st.size()) return st.size();
        else return n / 2;
    }
};
// @lc code=end

