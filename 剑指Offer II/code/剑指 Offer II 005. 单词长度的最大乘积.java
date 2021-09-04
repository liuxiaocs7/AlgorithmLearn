class Solution {
    public int maxProduct(String[] words) {
        int[] flags = new int[words.length];
        for(int i = 0; i < words.length; i++) {
            for(char ch : words[i].toCharArray()) {
                flags[i] |= (1 << (ch - 'a'));
            }
        }

        int res = 0;
        for(int i = 0; i < words.length; i++) {
            for(int j = i + 1; j < words.length; j++) {
                // 位运算与
                if((flags[i] & flags[j]) == 0) {
                    int prod = words[i].length() * words[j].length();
                    res = Math.max(res, prod);
                }
            }
        }
        return res;
    }
}