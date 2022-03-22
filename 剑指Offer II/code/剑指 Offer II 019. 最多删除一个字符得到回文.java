class Solution {
    public boolean validPalindrome(String s) {
        int n = s.length();
        int st = 0, ed = n - 1;
        while(st < ed && s.charAt(st) == s.charAt(ed)) {
            st++;
            ed--;
        }
        if(st >= ed) return true;
        return check(s, st + 1, ed) || check(s, st, ed - 1);
    }

    private boolean check(String s, int st, int ed) {
        while(st < ed) {
            if(s.charAt(st++) != s.charAt(ed--)) return false;
        }
        return true;
    }
}