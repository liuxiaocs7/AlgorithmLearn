# 0069 x-的平方根(Sqrt(x))

> 题目链接：[力扣](https://leetcode-cn.com/problems/sqrtx/) | [LeetCode](https://leetcode.com/problems/sqrtx/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2414/1/)

## 题目

实现 `int sqrt(int x)` 函数。

计算并返回 `x` 的平方根，其中 `x` 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

**示例 1:**

```plain
输入: 4
输出: 2
```

**示例 2:**

```plain
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```

---

## 思路1

【二分】$y^2<=x$，找 $y$ 的**最大值**，即找到左边区域的最大值，`l = 0，r = x` 开始，若 `mid * mid <= x`，则往右边找，否则往左边找，有可能溢出，使用 `1ll` 长整型，并且判断是用除法不用乘法 `mid <= x/mid`

> 时间复杂度 $O(logN)$，空间复杂度 $O(1)$

## 代码1

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r) {
            int mid = (l + r + 1ll) / 2;
            // 避免乘法溢出
            if(mid <= x / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

```java
class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(mid <= x / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
