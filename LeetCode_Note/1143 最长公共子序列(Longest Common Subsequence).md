# 1143 Longest Common Subsequence(最长公共子序列)

> 题目链接：[力扣](https://leetcode-cn.com/problems/longest-common-subsequence/) | [LeetCode](https://leetcode.com/problems/longest-common-subsequence/) | [AcWing](3)

## 题目

给定两个字符串 `text1` 和 `text2`，返回这两个字符串的**最长公共子序列**的长度。

一个字符串的 `子序列` 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:

```plain
输入：text1 = "abcde", text2 = "ace"
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
```

示例 2:

```plain
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
```

示例 3:

```plain
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
```

提示:

$1 <= text1.length <= 1000$  
$1 <= text2.length <= 1000$  
输入的字符串只含有小写英文字符。

---

## 思路1

DP分析：

- 状态表示：`dp[i][j]`表示上到字符串 `text1`长度为 `i`的子串与 `text2` 长度为 `j` 的子串的公共子序列长度
- 属性是**最大值**
- 状态计算：
  1. `text1`第`i`个字符与`text2`第`j`个字符相同
  2. `text1`第`i`个字符与`text2`第`j`个字符不相同，取两者中更大的一个

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N^2)$

## 代码1

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
