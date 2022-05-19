class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0, n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0, j = 0; i < n; i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
            while(map.get(c) > 1) {
                char cj = s.charAt(j);
                map.put(cj, map.get(cj) - 1);
                j++;

            }
            res = Math.max(res, i - j + 1);
        }
        return res;
    }
}