class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int m = a.length() - 1;
        int n = b.length() - 1;
        int t = 0;
        while(m >= 0 || n >= 0 || t != 0) {
            int digitA = m >= 0 ? a.charAt(m--) - '0' : 0;
            int digitB = n >= 0 ? b.charAt(n--) - '0' : 0;
            t = digitA + digitB + t;
            sb.append(t % 2);
            t /= 2;
        }
        return sb.reverse().toString();
    }
}