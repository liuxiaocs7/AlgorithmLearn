class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length() || s.equals(t)) return false;

        int[] count = new int[26];
        for(char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for(char c : t.toCharArray()) {
            if(count[c - 'a'] <= 0) {
                return false;
            }
            count[c - 'a']--;
        }

        return true;
    }
}