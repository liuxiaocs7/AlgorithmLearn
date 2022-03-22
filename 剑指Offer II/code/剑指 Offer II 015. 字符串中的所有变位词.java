class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = p.length(), m = s.length();
        List<Integer> res = new ArrayList<>();
        if(n > m) return res;

        int[] cnt = new int[26];
        for(int i = 0; i < n; i++) {
            cnt[p.charAt(i) - 'a']++;
            cnt[s.charAt(i) - 'a']--;
        }

        if(check(cnt)) res.add(0);

        for(int i = 1; i + n - 1 < m; i++) {
            cnt[s.charAt(i - 1) - 'a']++;
            cnt[s.charAt(i + n - 1) - 'a']--;
            if(check(cnt)) res.add(i);
        }
        return res;
    }

    private boolean check(int[] cnt) {
        for(int num : cnt) {
            if(num != 0) return false;
        }
        return true;
    }
}