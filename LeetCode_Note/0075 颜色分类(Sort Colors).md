# 0075 颜色分类(Sort Colors)

> 题目链接：[力扣](https://leetcode-cn.com/problems/sort-colors/) | [LeetCode](https://leetcode.com/problems/sort-colors/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2424/1/)

## 题目

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

```plain
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```

进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

---

## 思路1

![20200904110115](https://liuxiaooss.oss-cn-beijing.aliyuncs.com/img/20200904110115.png)

【双指针法】设置`j`为0和1的分界线，`k`为1和2的分界线，`i`用来遍历整个数组，初始时在两边。扫描一遍数组，遇到0则交换到前面，遇到1则继续遍历，遇到2则交换到后面。

注意点：

- 外层循环中的条件应该是 `i < k`表示最后一部分(2)已经排好了
- 如果遇到2的时候i不应该改变，因为可能会交换过来一个0.
- 即每种情况下要么是 `i++`要么是 `k--`，`i`和`j`一定会缩小距离直到相遇。

> 时间复杂度 $O(N)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0, j = 0, k = nums.size() - 1; i < k; i++)
        {
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else if(nums[i] == 2) swap(nums[i], nums[k--]);
            else i++;
        }
    }
};
```

---

## 思路2

直接排序，0，1，2的顺序即对应着红白蓝三种颜色

> 时间复杂度 $O(NlogN)$，空间复杂度 $O(1)$

## 代码2

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```

---

## 思路3

【计数排序法】第一次扫描依次统计每种颜色的数量，如`cnt[0]`表示**红色**的数量，第二次扫描按照(0,1,2)的顺序填入原来的数组。

> 时间复杂度 $O(N)$，空间复杂度 $O(1)$

## 代码3

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(const auto &it : nums)
            cnt[it]++;
        int k = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < cnt[i]; j++)
                nums[k++] = i;
    }
};
```
