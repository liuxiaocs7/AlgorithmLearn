/*
 * @lc app=leetcode.cn id=954 lang=java
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        int pos = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) neg++;
            else if(arr[i] > 0) pos++;
        }
        if(pos % 2 != 0 || neg % 2 != 0) return false;

        reverse(arr, 0, neg - 1);
        return check(arr, 0, neg - 1) && check(arr, n - pos, n - 1);
    }

    private void reverse(int[] arr, int st, int ed) {
        for(int i = st, j = ed; i < j; i++, j--) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    private boolean check(int[]arr, int st, int ed) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = ed - st + 1;
        for(int i = st; i <= ed; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        for(int i = st; i < ed; i++) {
            if(map.getOrDefault(arr[i], 0) == 0) continue;
            int t = arr[i] * 2;
            if(map.getOrDefault(t, 0) <= 0) return false;
            map.put(t, map.get(t) - 1);
            map.put(arr[i], map.get(arr[i]) - 1);
        }

        return true;
    }
}
// @lc code=end

