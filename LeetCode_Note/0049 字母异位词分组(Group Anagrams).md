# 0049 字母异位词分组(Group Anagrams)

> 题目链接：[力扣](https://leetcode-cn.com/problems/group-anagrams/) | [LeetCode](https://leetcode.com/problems/group-anagrams/) | [AcWing](3)

## 题目

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

```plain
输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

---

## 思路1

【哈希表，字符串】
由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$  
> 时间复杂度：$O(nk\log k)$，其中 $n$ 是 $\textit{strs}$ 中的字符串的数量，$k$ 是 $\textit{strs}$ 中的字符串的的**最大长度**。需要遍历 $n$ 个字符串，对于每个字符串，需要 $O(k \log k)$ 的时间进行**排序**以及 $O(1)$ 的时间**更新哈希表**，因此总时间复杂度是 $O(nk \log k)$。  
> 空间复杂度：$O(nk)$，其中 $n$ 是 $\textit{strs}$ 中的字符串的数量，$k$ 是 $\textit{strs}$ 中的字符串的的**最大长度**。需要用哈希表存储全部字符串。


## 代码1

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const auto &it: strs) {
            string key = it;
            sort(key.begin(), key.end());
            mp[key].emplace_back(it);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
```

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for(String str: strs) {
            char[] array = str.toCharArray();
            Arrays.sort(array);
            String key = new String(array);
            List<String> list = map.getOrDefault(key, new ArrayList<>());
            list.add(str);
            map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
