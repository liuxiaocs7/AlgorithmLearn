# 0119 杨辉三角 II(Pascal's Triangle II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/pascals-triangle-ii/) | [LeetCode](https://leetcode.com/problems/pascals-triangle-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2481/1/)

## 题目

给定一个非负索引 $k$，其中 $k ≤ 33$，返回杨辉三角的第 $k$ 行。

![题目](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

```plain
输入: 3
输出: [1,3,3,1]
```

进阶：

你可以优化你的算法到 $O(k)$ 空间复杂度吗？

---

## 思路1

计算第 `i` 层的时候只会用到第 `i-1`层的值，可以使用一个**滚动数组**进行计算。
先用一般的数组来写，最后改为**一维**的滚动数组。

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N^2)$

## 代码1

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            for(int j = i; j > 0; j--)
                ans[j] = ans[j - 1] + ans[j];
        return ans;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
