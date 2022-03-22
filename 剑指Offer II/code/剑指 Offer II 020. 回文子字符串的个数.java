class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += count(s, i, i);
            res += count(s, i, i + 1);
        }
        return res;
    }

    private int count(String s, int st, int ed) {
        int res = 0;
        while(st >= 0 && ed < s.length() && s.charAt(st) == s.charAt(ed)) {
            res++;
            st--;
            ed++;
        }
        return res;
    }
}