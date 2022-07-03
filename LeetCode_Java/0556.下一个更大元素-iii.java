/*
 * @lc app=leetcode.cn id=556 lang=java
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
    public int nextGreaterElement(int x) {
        List<Integer> list = new ArrayList<>();
        while(x != 0) {
            list.add(x % 10);
            x /= 10;
        }

        int n = list.size();
        int idx = -1;
        for(int i = 0; i < n - 1; i++) {
            if(list.get(i + 1) < list.get(i)) {
                idx = i + 1;
                break;
            }
        }

        if(idx == -1) return -1;

        for(int i = 0; i < idx; i++) {
            if(list.get(i) > list.get(idx)) {
                swap(list, i, idx);
                break;
            }
        }

        for(int i = 0, j = idx - 1; i < j; i++, j--) {
            swap(list, i, j);
        }

        long res = 0;
        for(int i = 0; i < n; i++) {
            res = res * 10 + list.get(n - i - 1);
        }
        return res > Integer.MAX_VALUE ? -1 : (int)res;
    }

    void swap(List<Integer> list, int i, int j) {
        int t = list.get(i);
        list.set(i, list.get(j));
        list.set(j, t);
    }
}
// @lc code=end

