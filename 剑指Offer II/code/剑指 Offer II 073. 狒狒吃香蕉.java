class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int r = 0;
        for(int pile : piles) {
            r = Math.max(r, pile);
        }

        int l = 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    private boolean check(int[] piles, int h, int k) {
        int cnt = 0;
        for(int pile : piles) {
            cnt += pile / k + (pile % k == 0 ? 0 : 1);
        }
        return cnt <= h;
    }
}