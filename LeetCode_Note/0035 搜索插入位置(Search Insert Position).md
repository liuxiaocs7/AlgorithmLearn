# 0035 搜索插入位置(Search Insert Position)

> 题目链接：[力扣](https://leetcode-cn.com/problems/search-insert-position/) | [LeetCode](https://leetcode.com/problems/search-insert-position/) | [AcWing](3)

## 题目

给定一个**排序数组**和一个**目标值**，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它**将会被按顺序插入的位置**。

你可以假设数组中无重复元素。

示例 1:

```plain
输入: [1,3,5,6], 5
输出: 2
```

示例 2:

```plain
输入: [1,3,5,6], 2
输出: 1
```

示例 3:

```plain
输入: [1,3,5,6], 7
输出: 4
```

示例 4:

```plain
输入: [1,3,5,6], 0
输出: 0
```

---

## 思路1

【数组，二分】

1. 有序数组二分，找到第一个大于等于 `target` 的位置，如果这个位置上的数等于 `target` 或者大于 `target` 都是满足条件的。

---

注意：题目中给出了条件是**有序数组**，遇到这种情况需要考虑**二分**，

> 时间复杂度 $O(logN)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (r - l) >> 1 + l;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
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
