# 0153 寻找旋转排序数组中的最小值(Find Minimum in Rotated Sorted Array).md

> 题目链接：[力扣](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) | [LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [AcWing](3)

## 题目

假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

请找出其中最小的元素。

示例 1：

输入：nums = [3,4,5,1,2]
输出：1
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
示例 3：

输入：nums = [1]
输出：1

提示：

1 <= nums.length <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数都是 唯一 的
nums 原来是一个升序排序的数组，但在预先未知的某个点上进行了旋转

---

## 思路1

> 时间复杂度 $O(logN)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[r] > nums[l]) return nums[l];
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r];
    }
};
```

```java
class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        // 特殊情况，单调递增的
        if(nums[r] >= nums[l]) return nums[0];
        // 二分出小于nums[0]的第一个位置即为分界点
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r];
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
