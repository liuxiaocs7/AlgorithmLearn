/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
    int m;
    int n;
    vector<string> res;
    unordered_set<string> st;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for(auto word : words) {
            st.insert(word);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<bool>> flag(m, vector<bool>(n));
                dfs(i, j, "", flag, board);
            }
        }
        return res;
    }

    void dfs(int i, int j, string str, vector<vector<bool>> &flag, vector<vector<char>>& board) {
        if(i < 0 || i >= m || j < 0 || j >= n || flag[i][j] || str.size() >= 10) {
            return;
        }
        string t = str + board[i][j];
        if(st.count(t)) {
            res.push_back(t);
            st.erase(t);
        }

        for(int k = 0; k < 4; k++) {
            flag[i][j] = true;
            int x = i + dx[k], y = j + dy[k];
            dfs(x, y, t, flag, board);
            flag[i][j] = false;
        }
    }
};
// @lc code=end

