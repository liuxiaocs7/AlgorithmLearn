/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
    int N;
    vector<bool> col, dg, udg;
public:
    int totalNQueens(int n) {
        N = n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        return dfs(0);
    }

    int dfs(int u)
    {
        if(u == N) return 1;
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            if(!col[i] && !dg[u - i + N] && !udg[u + i])
            {
                col[i] = dg[u - i + N] = udg[u + i] = true;
                res += dfs(u + 1);
                col[i] = dg[u - i + N] = udg[u + i] = false;
            }
        }
        return res;
    }
};
// @lc code=end

