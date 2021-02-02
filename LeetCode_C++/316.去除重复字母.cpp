/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        vector<bool> vis(26);
        vector<int> st;
        int n = s.size();

        for(int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;

        for(int i = 0; i < n; i++)
        {
            if(vis[s[i] - 'a']) continue;

            while(!st.empty() && st.back() > s[i])
            {
                if(last[st.back() - 'a'] < i) break;

                vis[st.back() - 'a'] = false;
                st.pop_back();
            }
            vis[s[i] - 'a'] = true;
            st.push_back(s[i]);
        }

        string ans;
        for(char c : st)
            ans += c;
        return ans;
    }
};
// @lc code=end

