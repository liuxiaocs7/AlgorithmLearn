/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */

// @lc code=start
class Solution {
    bool vis[4] = {false};
    string ans, t;
public:
    string largestTimeFromDigits(vector<int>& A) {
        dfs(0, "", A);
        if(ans.size())
            t = ans.substr(0, 2) + ":" + ans.substr(2);
        return t;
    }

    void dfs(int u, string res, vector<int>& A)
    {
        if(u == 4)
        {
            string hour = res.substr(0, 2);
            string minute = res.substr(2);
            if(hour >= "00" && hour <= "23" && minute >= "00" && minute <= "59" && res > ans)
                ans = res;
        }

        for(int i = 0; i < 4; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                dfs(u + 1, res + to_string(A[i]), A);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

