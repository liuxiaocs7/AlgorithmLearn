class Solution {
    public int[] countBits(int n) {
        int[] res = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            // 注意运算优先级，(i & 1)括号不能省略
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
}