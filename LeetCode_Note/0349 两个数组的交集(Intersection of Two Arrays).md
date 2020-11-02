# 0349 两个数组的交集(Intersection of Two Arrays)

> 题目链接：[力扣](https://leetcode-cn.com/problems/intersection-of-two-arrays/) | [LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2737/1/)

## 题目

给定两个数组，编写一个函数来计算它们的**交集**。

示例 1：

```plain
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

示例 2：

```plain
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
```

说明：

输出结果中的每个元素一定是唯一的。  
我们可以不考虑输出结果的顺序。

---

## 思路1

【哈希】将数组 `nums1` 中的数据全部加入集合(set) `S` 中(实现方式可以是①直接构造、②逐个插入)，在加入的过程中数组 `nums1` 中的数据会被自动去重，逐个遍历数组 `nums2` 中的数据，如果这个数据在集合 `S` 中出现过，将其加入答案数组 `ans` 中，同时在原来的集合 `S` 中删除这个数据保证**唯一性**。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

遍历数组 `nums1` 和数组 `nums2` 时间为 $O(N)$，使用了额外的哈希表的空间 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S(nums1.begin(), nums1.end());
        vector<int> ans;

        for(const auto &it : nums2)
        {
            if(S.count(it))
            {
                ans.push_back(it);
                S.erase(it);
            }
        }
        return ans;
    }
};
```

【哈希】声明一个集合 `s` 存储数组 `nums1` 中的数据，集合 `intersect` 存储两者交集中的数据。最后将交集中的数据存入数组 `ans` 中。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

遍历数组 `nums1` 和数组 `nums2` 时间为 $O(N)$，使用了额外的哈希表的空间 $O(N)$

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s = new HashSet<>();
        Set<Integer> intersect = new HashSet<>();
        for(int i = 0; i < nums1.length; i++) {
            s.add(nums1[i]);
        }

        for(int i = 0; i < nums2.length; i++) {
            if(s.contains(nums2[i])) {
                intersect.add(nums2[i]);
            }
        }

        int[] ans = new int[intersect.size()];
        int i = 0;
        for(Integer num : intersect) {
            ans[i++] = num;
        }
        return ans;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
