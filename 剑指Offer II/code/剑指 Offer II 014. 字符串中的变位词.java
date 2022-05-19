class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        if(n >  s2.length()) return false;
        int[] cnt = new int[26];
        for(int i = 0; i < n; i++) {
            cnt[s1.charAt(i) - 'a']++;
            cnt[s2.charAt(i) - 'a']--;
        }

        int k = n;
        while(k < s2.length() && !check(cnt)) {
            cnt[s2.charAt(k) - 'a']--;
            cnt[s2.charAt(k - n) - 'a']++;
            k++;
        }
        if(check(cnt)) return true;
        return false;
    }

    private boolean check(int[] cnt) {
        for(int num : cnt) {
            if(num != 0) return false;
        }
        return true;
    }
}