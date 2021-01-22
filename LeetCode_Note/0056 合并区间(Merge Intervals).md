# 0056 合并区间

> 题目链接：[力扣](https://leetcode-cn.com/problems/merge-intervals/) | [LeetCode](https://leetcode.com/problems/merge-intervals/) | [AcWing](3)

## 题目

给出一个区间的集合，请合并所有重叠的区间。

示例 1:

```plain
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

示例 2:

```plain
输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
```

提示：

```plain
intervals[i][0] <= intervals[i][1]
```

---

## 思路1

【数组，排序】

1. 对数组排序(按照第一个维度从小到大)
2. 定义二维数组 `ans` 作为答案
3. 对于之后的每个区间，存在两种情况：
   1. 新遍历的子区间的左端点 `l` 比 `ans` 的最后面一个区间的右端点要**小**，此时需要新建一个区间加入 `ans`
   2. 新遍历的子区间的左端点 `l` 比 `ans` 的最后面一个区间的右端点要**大**，此时需要将这个子区间合并到 `ans` 中最后一个子数组上，由于左端点之前已经排序过，因此此时右端点需要取两者中较大值。

> 时间复杂度 $O(NlonN)$，空间复杂度 $O(logN)$

## 代码1

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(ans.size() == 0 || ans.back()[1] < l) {
                ans.push_back({l, r});
            } else {
                ans.back()[1] = max(ans.back()[1], r);
            }
        }
        return ans;
    }
};
```

```java

```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
