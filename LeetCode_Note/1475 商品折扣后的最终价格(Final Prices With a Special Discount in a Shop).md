# 1475 商品折扣后的最终价格(Final Prices With a Special Discount in a Shop)

> 题目链接：[力扣](https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/) | [LeetCode](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) | [AcWing](3)

## 题目

给你一个数组 `prices` ，其中 `prices[i]` 是商店里第 `i` 件商品的价格。

商店里正在进行促销活动，如果你要买第 `i` 件商品，那么你可以得到与 `prices[j]` 相等的折扣，其中 `j` 是满足 `j > i` 且 `prices[j] <= prices[i]` 的 最小下标 ，如果没有满足条件的 `j` ，你将没有任何折扣。

请你返回一个数组，数组中第 `i` 个元素是折扣后你购买商品 `i` 最终需要支付的价格。

示例 1：

```
输入：prices = [8,4,6,2,3]
输出：[4,2,4,2,3]
解释：
商品 0 的价格为 price[0]=8 ，你将得到 prices[1]=4 的折扣，所以最终价格为 8 - 4 = 4 。
商品 1 的价格为 price[1]=4 ，你将得到 prices[3]=2 的折扣，所以最终价格为 4 - 2 = 2 。
商品 2 的价格为 price[2]=6 ，你将得到 prices[3]=2 的折扣，所以最终价格为 6 - 2 = 4 。
商品 3 和 4 都没有折扣。
```

示例 2：

```
输入：prices = [1,2,3,4,5]
输出：[1,2,3,4,5]
解释：在这个例子中，所有商品都没有折扣。
```

示例 3：

```
输入：prices = [10,1,1,6]
输出：[9,0,1,6]
```

提示：

- `1 <= prices.length <= 500`
- `1 <= prices[i] <= 10^3`

---

## 思路1

【单调栈】

- 维护一个单调递增栈，每个数右边且比这个数大的数一定不会作为答案，直接出栈
- 使用当前数和当前数右边距离最近且比当前数小的数据更新答案
- 将当前价格入栈

每个数最多进栈一次，出栈一次，因此

- 时间复杂度 $O(N)$
- 空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && stk.top() > prices[i]) {
                stk.pop();
            }
            res[i] = prices[i] - (stk.size() ? stk.top() : 0);
            stk.push(prices[i]);
        }
        return res;
    }
};
```

```java
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        Deque<Integer> d = new ArrayDeque<>();
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            while (!d.isEmpty() && d.peekLast() > prices[i]) {
                d.pollLast();
            }
            res[i] = prices[i] - (d.isEmpty() ? 0 : d.peekLast());
            d.offerLast(prices[i]);
        }
        return res;
    }
}
```
