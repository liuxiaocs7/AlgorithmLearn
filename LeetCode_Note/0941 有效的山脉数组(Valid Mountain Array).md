# 0941 有效的山脉数组(Valid Mountain Array)

> 题目链接：[力扣](https://leetcode-cn.com/problems/valid-mountain-array/) | [LeetCode](https://leetcode.com/problems/valid-mountain-array/) | [AcWing](3)

## 题目

给定一个整数数组 `A`，如果它是有效的山脉数组就返回 `true`，否则返回 `false`。

让我们回顾一下，如果 `A` 满足下述条件，那么它是一个山脉数组：

- $A.length >= 3$
- 在 $0 < i < A.length - 1$ 条件下，存在 $i$ 使得：  
$A[0] < A[1] < ... A[i-1] < A[i]$  
$A[i] > A[i+1] > ... > A[A.length - 1]$

![题目1](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

![题目2](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

---

## 思路1

【模拟，线性扫描】由山脉数组的定义可知数组有一段单增一段单减构成，其中山顶的位置不在两边的位置(即坐标不为 `0` 和 `n - 1`，此时整个数组是单调的)。

1. 模拟单增的情况 `A[i] < A[i + 1]`，注意不越界 `i < n - 1` 因为有 `A[i + 1]`。找到第一个不满足条件的下标 `i` 就是这个数组最高点的下标。
2. 如果出现单调的情况，返回 `false`。
3. 模拟单减的情况 `A[i] < A[i + 1]`，注意不越界。
4. 若最后 `i` 的下标为 `i - 1` 表示整个数组是符合山脉条件的。

> 时间复杂度 $O(N)$，空间复杂度 $O(1)$

遍历整个数组，时间复杂度为数组长度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int i = 0;
        while(i + 1 < n && A[i] < A[i + 1]) i++;
        if(i == 0 || i == n - 1) return false;
        while(i + 1 < n && A[i] > A[i + 1]) i++;
        return i == n - 1;
    }
};
```

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int n = A.length;
        int i = 0;
        while(i < n - 1 && A[i] < A[i + 1]) i++;
        if(i == 0 || i == n - 1) return false;
        while(i < n - 1 && A[i] > A[i + 1]) i++;
        return i == n - 1;
    }
}
```

---

## 思路2

采用类似**双指针**的思想，从两个方向向中间靠拢。最后的结束条件是 `i` 至少往右走一步，`j` 至少往左走一步，并且两个表示山峰的位置应该相等。

> 时间复杂度 $O(N)$，空间复杂度 $O(1)$

## 代码2

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        while(i < n - 1 && A[i] < A[i + 1]) i++;
        while(j > 0 && A[j] < A[j - 1]) j--;
        return i > 0 && i == j && j < n - 1;
    }
};
```

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int n = A.length, i = 0, j = n - 1;
        while(i < n - 1 && A[i] < A[i + 1]) i++;
        while(j > 0 && A[j] < A[j - 1]) j--;
        return i > 0 && i == j && j < n - 1;
    }
}
```
