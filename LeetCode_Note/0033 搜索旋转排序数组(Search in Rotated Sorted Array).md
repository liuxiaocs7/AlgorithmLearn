# 0033 搜索旋转排序数组(Search in Rotated Sorted Array)

> 题目链接：[力扣](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [AcWing](3)

## 题目

升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。

请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1

提示：

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums 中的每个值都 独一无二
nums 肯定会在某个点上旋转
-10^4 <= target <= 10^4

---

## 思路1

【二分】

1. 找到分界点，分为两段，依据是整个区间的**数前半区间**中满足 `x >= nums[0]`，后半区间不满足，则可以二分出这个位置(边界点就是满足这个性质的最后一个数)
2. 根据 `target` 和 `nums[0]` 的大小关系确定 `target` 具体在哪个区间中，再进行一次二分即可。这次二分中条件为 `x >= target` 的第一个数

> 时间复杂度 $O(logN)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;

        // 二分出 >= nums[0] 的分界点
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        // 结果在前半区间中，此时 r = l = 分界点
        if(target >= nums[0]) {
            // 重置l下一次二分
            l = 0;
        } else {
            l = l + 1;
            r = nums.size() - 1;
        }
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[r] == target ? r : -1;
    }
};
```

```java
class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if(target >= nums[0]) {
            l = 0;
        } else {
            l = l + 1;
            r = nums.length - 1;
        }

        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r] == target ? r : -1;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
