class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] count = new int[26];
        for(int i = 0; i < 26; i++) {
            count[order.charAt(i) - 'a'] = i;
        }

        for(int i = 1; i < words.length; i++) {
            if(!sorted(words[i - 1], words[i], count)) {
                return false;
            }
        }
        return true;
    }

    private boolean sorted(String s1, String s2, int[] count) {
        for(int i = 0; i < s1.length() || i < s2.length(); i++) {
            int c1 = -1, c2 = -1;
            if(i < s1.length()) c1 = count[s1.charAt(i) - 'a'];
            if(i < s2.length()) c2 = count[s2.charAt(i) - 'a'];
            if(c1 != c2) return c1 < c2;
        }
        return true;
    }
}