class Solution {
    public int mySqrt(int x) {
        if(x == 0) return 0;
        long l = 1, r = x;
        while(l < r) {
            long mid = l + r + 1 >> 1;
            if(mid * mid <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (int)l;
    }
}