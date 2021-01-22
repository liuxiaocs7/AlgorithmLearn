# 0048 旋转图像(Rotate Image)

> 题目链接：[力扣](https://leetcode-cn.com/problems/rotate-image/) | [LeetCode](https://leetcode.com/problems/rotate-image/) | [AcWing](3)

## 题目

给定一个 $n × n$ 的二维矩阵表示一个图像。

将图像顺时针旋转 `90` 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

```plain
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

示例 2:

```plain
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
通过次数138,762提交次数192,417
```

---

## 思路1

【数组】

1. 沿对角线翻转
2. 行内翻转

> 时间复杂度 $O(N^2)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return;

        // 对角线翻转
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 行内翻转
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

```java

```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
