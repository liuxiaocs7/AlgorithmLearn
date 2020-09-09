# 0127 单词接龙(Word Ladder)

> 题目链接：[力扣](https://leetcode-cn.com/problems/word-ladder/) | [LeetCode](https://leetcode.com/problems/word-ladder/) | [AcWing](https://www.acwing.com/activity/content/code/content/394573/)

## 题目

给定两个单词（`beginWord` 和 `endWord`）和一个字典，找到从 `beginWord` 到 `endWord` 的**最短**转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 `beginWord` 和 `endWord` 是**非空**的，且二者不相同。

示例 1:

```plain
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
```

示例 2:

```plain
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
```

---

## 思路1

【BFS】

1. 用**哈希**表记录每个单词到起点 `beginWord` 的**最短**距离
2. 从起点位置标记长度是 `1`，从起点 `beginWord` 开始出发，若下一个单词 `word` 能和队列队首单词 `s` 连上一条边，且哈希表中**不存在**，则更新下一个单词 `word` 的到起点的距离 `dist[word] = dist[s] + 1`，并加入到队列中
3. 最后返回 `dist[endWord]`

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
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
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
