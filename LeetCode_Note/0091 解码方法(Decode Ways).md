# 0091 解码方法(Decode Ways)

> 题目链接：[力扣](https://leetcode-cn.com/problems/decode-ways/) | [LeetCode](https://leetcode.com/problems/decode-ways/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2444/1/)

## 题目

一条包含字母 `A-Z` 的消息通过以下方式进行了编码：

```plain
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

```plain
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
```

```plain
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```

---

## 思路1

DP分析：

- 状态表示：所有由前 `i`个字符可以解码回去的字符串的集合(个数)
- 属性是**个数**
- 状态计算：要么结尾的一位数字表示一个字符(`1-9` $f(i - 1$)，要么结尾的两个数字表示一个字符(`10-26` $f(i - 2)$）

$$dp[i] = dp[i - 1] + dp[i - 2]$$

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            if(i > 1)
            {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                if(t >= 10 && t <= 26) dp[i] += dp[i - 2];
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
