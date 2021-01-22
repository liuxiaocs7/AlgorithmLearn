# 0724 寻找数组的中心索引(Find Pivot Index)

> 题目链接：[力扣](https://leetcode-cn.com/problems/find-pivot-index/) | [LeetCode](https://leetcode.com/problems/find-pivot-index/) | [AcWing](3)

## 题目

给定一个整数类型的数组 `nums`，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 **中心索引** 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 `-1`。如果数组有多个中心索引，那么我们应该返回**最靠近左边**的那一个。

示例 1：

```plain
输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。
```

示例 2：

```plain
输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。
```

说明：

`nums` 的长度范围为 `[0, 10000]`。
任何一个 `nums[i]` 将会是一个范围在 `[-1000, 1000]` 的整数。

---

## 思路1

【数组】

1. 第一次遍历求数组所有元素之和 `sum`
2. 第二次遍历查看左边等于右边的位置，`leftSum == sum - nums[i] - leftSum`表示下标为 `i` 的位置为所求。

> 时间复杂度 $O(N)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        for(const auto &it : nums) {
            sum += it;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(leftSum == sum - nums[i] - leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
```

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftSum = 0;
        for(int num : nums) {
            sum += num;
        }

        for(int i = 0; i < nums.length; i++) {
            if(leftSum == sum - nums[i] - leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
