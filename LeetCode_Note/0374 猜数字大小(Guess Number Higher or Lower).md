# 0374 猜数字大小(Guess Number Higher or Lower)

> 题目链接：[力扣](https://leetcode-cn.com/problems/guess-number-higher-or-lower/) | [LeetCode](https://leetcode.com/problems/guess-number-higher-or-lower/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2750/1/)

## 题目

猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1：我选出的数字比你猜的数字小 pick < num
1：我选出的数字比你猜的数字大 pick > num
0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
返回我选出的数字。

**示例 1：**

```plain
输入：n = 10, pick = 6
输出：6
```

**示例 2：**

```plain
输入：n = 1, pick = 1
输出：1
```

**示例 3：**

```plain
输入：n = 2, pick = 1
输出：1
```

**示例 4：**

```plain
输入：n = 2, pick = 2
输出：2
``` 

提示：

- $1 <= n <= 2^31 - 1$
- `1 <= pick <= n`

---

## 思路1

【二分】接口已经给出了，二分出第一个大于等于 `pick` 值的位置。

> 时间复杂度 $O(logN)$，空间复杂度 $O(1)$

## 代码1

```cpp
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(guess(mid) <= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

```java
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(guess(mid) <= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

使用一般模板

```java
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int ans = guess(mid);
            if(ans == 0) {
                return mid;
            } else if(ans > 0) {
                l = mid + 1;
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
