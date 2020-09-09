# 0118 杨辉三角(Pascal's Triangle)

> 题目链接：[力扣](https://leetcode-cn.com/problems/pascals-triangle/) | [LeetCode](https://leetcode.com/problems/pascals-triangle/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2480/1/)

## 题目

给定一个非负整数 $numRows$，生成杨辉三角的前 $numRows$ 行。

![题目动图](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

```plain
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

---

## 思路1

【递推】从上到下依次计算每一行；对于每一行，先把1放在首位两个位置，然后计算中间的数：$f[i][j] = f[i-1][j-1] + f[i-1][j];$

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N^2)$

## 代码1

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++)
        {
            ans[i].resize(i + 1, 1);
            for(int j = 1; j < i; j++)
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        return ans;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N^2)$

## 代码2

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1);
            row[0] = row[i] = 1;
            for(int j = 1; j < i; j++)
            {
                row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans.push_back(row);
        }
        return ans;
    }
};
```
