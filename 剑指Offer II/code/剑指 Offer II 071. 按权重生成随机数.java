class Solution {

    Map<Integer, Integer> numToIndex = new HashMap<>();
    List<Integer> list = new ArrayList<>();
    int idx = 0;

    public Solution(int[] w) {
        int n = w.length;
        for(int i = 0; i < n; i++) {
            numToIndex.put(idx, i);
            list.add(idx);
            idx += w[i];
        }
    }
    
    public int pickIndex() {
        Random random = new Random();
        int pick = random.nextInt(0, idx);

        int l = 0, r = list.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(list.get(mid) <= pick) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return numToIndex.get(list.get(l));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */