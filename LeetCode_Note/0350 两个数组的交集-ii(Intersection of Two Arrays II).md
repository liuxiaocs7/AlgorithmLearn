# 0350 两个数组的交集-ii(Intersection of Two Arrays II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/) | [LeetCode](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2738/1/)

## 题目

给定两个数组，编写一个函数来计算它们的交集。

示例 1：

```plain
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
```

示例 2:

```plain
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
```

说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。
进阶：

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

---

## 思路1

【哈希】

1. 首先将数组 `nums1` 中的数据存入哈希表 `s` 中，这里需要使用 `unordered_multiset<int>` 而不是 `unordered_set<int>` 因为数组中可能包含有**重复元素**。
2. 遍历数组 `nums2`，对于每个数 $x$，如果 $x$ 出现在哈希表中，则将 $x$ 存入答案数组 `ans` 中，并从哈希表 `s` 中**删除一个** `x`

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

假设两个数组的长度分别是 $n, m$，将 `nums1` 存入哈希表的计算量是 $O(n)$，遍历 `nums2` 的计算量是 $O(m)$，总的时间复杂度为 `O(n + m)`

思考题：

1. 如果给定的数组已经排好序，你可以怎样优化你的算法？
答：可以用**双指针**扫描。这样可以把空间复杂度降为 $O(1)$，但时间复杂度还是 $O(n)$；
2. 如果数组 `nums1` 的长度小于数组 `nums2` 的长度，哪种算法更好？、
答：可以把 `nums1` 存入哈希表，然后遍历 `nums2`。这样可以使用更少的内存(长度小占用空间小)，但时空复杂度仍是 $O(n)$；
3. 如果数组 `nums2` 存储在硬盘上，然而内存是有限的，你不能将整个数组都读入内存，该怎么做？
答：如果 `nums1` 可以存入内存，则可以将 `nums1` 存入哈希表，然后分块将 `nums2` 读入内存，进行查找；如果两个数组都不能存入内存，可以先将两个数组分别排序，比如可以用外排序，然后用类似于双指针扫描的方法，将两个数组分块读入内存，进行查找。

## 代码1

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for(const auto &it : nums2)
        {
            if(s.count(it))
            {
                ans.push_back(it);
                s.erase(s.find(it));
            }
        }
        return ans;
    }
};
```

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for(int i = 0; i < nums1.length; i++) {
            if(mp.containsKey(nums1[i])) mp.put(nums1[i], mp.get(nums1[i]) + 1);
            else mp.put(nums1[i], 1);
        }

        for(int i = 0; i < nums2.length; i++) {
            if(mp.containsKey(nums2[i]) && mp.get(nums2[i]) > 0) {
                ans.add(nums2[i]);
                mp.put(nums2[i], mp.get(nums2[i]) - 1);
            }
        }

        int[] res = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }
        return res;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
