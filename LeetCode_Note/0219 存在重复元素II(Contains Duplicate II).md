# 0219. 存在重复元素 II(Contains Duplicate II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/contains-duplicate-ii/) | [LeetCode](https://leetcode.com/problems/contains-duplicate-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2600/1/)

## 题目

给定一个整数数组和一个整数 $k$，判断数组中是否存在两个不同的索引 $i$ 和 $j$，使得 $nums [i] = nums [j]$，并且 $i$ 和 $j$ 的差的 绝对值 至多为 $k$。

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

1. 之前没有出现过，则将其添加到哈希表`map`中
2. 之前出现过，则判断**下标之差**是否小于 $k$，若小于则找到了一个答案(对应于题目中的**存在**)，否则**更新**出现这个数的最新位置以得到**最小**的位置下标之差(为了满足存在条件)。

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
