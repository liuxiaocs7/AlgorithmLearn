# 0205 同构字符串(Isomorphic Strings)

> 题目链接：[力扣](https://leetcode-cn.com/problems/isomorphic-strings/) | [LeetCode](https://leetcode.com/problems/isomorphic-strings/) | [AcWing](3)

## 题目

给定两个字符串 `s` 和 `t`，判断它们是否是同构的。

如果 `s` 中的字符可以按某种映射关系替换得到 `t` ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

示例 1:

```plain
输入：s = "egg", t = "add"
输出：true
```

示例 2：

```plain
输入：s = "foo", t = "bar"
输出：false
```

示例 3：

```plain
输入：s = "paper", t = "title"
输出：true
```

提示：

可以假设 s 和 t 长度相同。

---

## 思路1

【哈希表】
定义两个哈希 `Map` 双向映射，`s2t` 表示字符串 `s` 中字符对字符串 `t` 中字符的映射，同理 `t2s` 表示字符串 `t` 中字符对字符串 `s` 中字符的映射。如果遍历到某个字符在哈希表中出现过并且和之前的映射不同，即为 `false` 否则需要添加映射。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
```

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> s2t = new HashMap<>();
        Map<Character, Character> t2s = new HashMap<>();

        for(int i = 0; i < s.length(); i++) {
            char x = s.charAt(i), y = t.charAt(i);
            if(s2t.containsKey(x) && s2t.get(x) != y || t2s.containsKey(y) && t2s.get(y) != x) {
                return false;
            }
            s2t.put(x, y);
            t2s.put(y, x);
        }
        return true;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
