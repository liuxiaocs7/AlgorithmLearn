# 0034 在排序数组中查找元素的第一个和最后一个位置(Find First and Last Position of Element in Sorted Array)

> 题目链接：[力扣](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [AcWing](3)

## 题目

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

---

## 思路1

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int s = -1;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (r - l) / 2 + l; // (l + r) >> 1
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(nums[l] != target) {
            return {-1, -1};
        } else {
            s = l;
            l = 0, r = nums.size() - 1;
            while(l < r) {
                int mid = (r - l + 1) / 2 + l;  // (l + r + 1) >> 1
                if(nums[mid] <= target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return {s, l};
        }
        return {-1, -1};
    }
};
```

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0, r = nums.length - 1, s = 0;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(nums.length == 0 || nums[r] != target) {
            return new int[]{-1, -1};
        } else {
            s = l;
            l = 0;
            r = nums.length - 1;
            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if(nums[mid] <= target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return new int[]{s, l};
        }
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
