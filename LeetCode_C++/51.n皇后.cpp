/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
    int N;
    vector<bool> col, dg, udg;
    vector<vector<string>> ans;
    vector<string> path;
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));
        dfs(0);
        return ans;
    }

    void dfs(int u)
    {
        if(u == N)
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < N; i++)
        {
            if(!col[i] && !dg[u - i + N] && !udg[u + i])
            {
                col[i] = dg[u - i + N] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[u - i + N] = udg[u + i] = false;
            }
        }
    }
};
// @lc code=end

