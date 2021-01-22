# 0771 宝石与石头(Jewels and Stones)

> 题目链接：[力扣](https://leetcode-cn.com/problems/jewels-and-stones/) | [LeetCode](https://leetcode.com/problems/jewels-and-stones/) | [AcWing](3)

## 题目

给定字符串 `J` 代表石头中宝石的类型，和字符串 `S` 代表你拥有的石头。 `S` 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

`J` 中的字母不重复，`J` 和 `S` 中的所有字符都是字母。字母区分大小写，因此 `a` 和 `A` 是不同类型的石头。

示例 1:

```plain
输入: J = "aA", S = "aAAbbbb"
输出: 3
```

示例 2:

```plain
输入: J = "z", S = "ZZ"
输出: 0
```

注意:

`S` 和 `J` 最多含有 `50` 个字母。
`J` 中的字符不重复。

---

## 思路1

【哈希表】

1. 使用一个 `Set` 存储所有宝石的类型
2. 遍历自己拥有的所有石头，如果是一个宝石(在 `Set` 里面)，则 `ans++`

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(const auto &it : jewels) {
            st.insert(it);
        }

        int ans = 0;
        for(const auto &it : stones) {
            if(st.count(it)) {
                ans++;
            }
        }
        return ans;
    }
};
```

```java
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> st = new HashSet<>();
        for(char c : jewels.toCharArray()) {
            st.add(c);
        }

        int ans = 0;
        for(int i = 0; i < stones.length(); i++) {
            if(st.contains(stones.charAt(i))) {
                ans++;
            }
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
