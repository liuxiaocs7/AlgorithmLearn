/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> dist;  // 变化的步数
        dist[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            string r = t;  // 暂存当前字符串
            for(int i = 0; i < t.size(); i++)
            {
                t = r;
                for(char j = 'a'; j <= 'z'; j++)
                {
                    t[i] = j;
                    if(st.count(t) && !dist.count(t))
                    {
                        dist[t] = dist[r] + 1;  // 从r变到t
                        if(t == endWord) return dist[t];
                        q.push(t);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

