# 0000 中文题目(英文题目)

> 题目链接：[力扣](https://leetcode-cn.com/problems/contains-duplicate-ii/) | [LeetCode](2) | [AcWing](3)

## 题目

给定一个整数数组和一个整数 $k$，判断数组中是否存在两个不同的索引 i 和 $j$，使得 $nums [i] = nums [j]$，并且 $i$ 和 $j$ 的差的 绝对值 至多为 $k$。

示例 1:

```plain
输入: nums = [1,2,3,1], k = 3
输出: true
```

示例 2:

```plain
输入: nums = [1,0,1,1], k = 1
输出: true
```

示例 3:

```plain
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
```

---

## 思路1

遍历每个数，对这个数而言，会存在以下两种情况：

1. 之前没有出现过，则将其添加到哈希表map中
2. 之前出现过，则判断**下标之差**是否小于 $k$，若小于则找到了答案，否则更新出现这个数的最新位置以得到**最小**的位置下标之差。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        bool ans = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp.count(nums[i]))
            {
                mp[nums[i]] = i;
            }
            else
            {
                if(i - mp[nums[i]] <= k)
                    ans = true;
                mp[nums[i]] = i;  // 保证最小
            }
        }
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
