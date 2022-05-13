class Solution {
    public boolean oneEditAway(String first, String second) {
        int m = first.length(), n = second.length();
        int sub = m - n;
        if (Math.abs(sub) > 1) return false;
        
        int cnt = 0;
        for(int i = 0, j = 0; i < m && j < n; ) {
            char c1 = first.charAt(i), c2 = second.charAt(j);
            if(c1 != c2 && ++cnt > 1) break;
            if(c1 == c2 || sub == 0) {
                i++; j++;
            } else if(sub == 1) {
                i++;
            } else {
                j++;
            }
        }
        return cnt <= 1;
    }
}