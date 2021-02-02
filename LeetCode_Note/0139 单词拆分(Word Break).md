# 0139 单词拆分(Word Break)

> 题目链接：[力扣](https://leetcode-cn.com/problems/word-break/) | [LeetCode](https://leetcode.com/problems/word-break/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2509/1/)

## 题目

给定一个非空字符串 `s` 和一个包含非空单词的列表 `wordDict`，判定 `s` 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以**重复使用**字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：

```plain
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
```

示例 2：

```plain
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
```

示例 3：

```plain
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
```

---

## 思路1

DP分析：

- 状态表示：`dp[i]`表示 `S[i-i]` 中所有合法划分方案
- 属性是**是否可以进行划分(划分的集合是否为空)**
- 状态计算：

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        s = " " + s;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                string t = s.substr(j, i - j + 1);
                if(dict.count(t) && dp[j - 1]) dp[i] = true;
            }
        }
        return dp[n];
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
