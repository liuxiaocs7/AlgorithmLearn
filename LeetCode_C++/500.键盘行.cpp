/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},
            {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3} 
        };

        vector<string> ans;
        for(auto &word: words) {
            int k = -1;
            bool flag = true;
            for(auto c : word) {
                c = tolower(c);
                if(k == -1) k = mp[c];
                else if(k != mp[c]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end

