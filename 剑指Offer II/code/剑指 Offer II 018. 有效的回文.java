class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
                sb.append(c);
            }
        }
        String res = sb.toString();
        int n = res.length();
        for(int i = 0; i < n / 2; i++) {
            if(res.charAt(i) != res.charAt(n - i - 1)) {
                return false;
            }
        }
        return true;
    }
}