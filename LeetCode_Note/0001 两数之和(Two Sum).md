# 0001 两数之和(Two Sum)

> 题目链接：[力扣](https://leetcode-cn.com/problems/two-sum/) | [LeetCode](https://leetcode.com/problems/two-sum/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2326/1/)

## 题目

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

```plain
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

---

## 思路1

【哈希】使用一个哈希表 `mp` 记录已经遍历过的数字和其对应的下标，如果与当前的数字 `nums[i]` 和为 `target` 的数字之前没有出现过则将这个数字 `nums[i]` 加入哈希表，否则找到了和为 `target` 的数字对，其下标分别为 `i` 和 `mp[target - nums[i]]`.

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp.count(target - nums[i]))
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
        return {};
    }
};
```

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            if(mp.containsKey(target - nums[i])) {
                return new int[]{mp.get(target - nums[i]), i};
            }
            mp.put(nums[i], i);
        }
        return new int[0];
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
