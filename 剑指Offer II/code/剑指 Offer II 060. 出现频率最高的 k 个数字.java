class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
            (o1, o2) -> o1.getValue() - o2.getValue()
        );
        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(minHeap.size() < k) {
                minHeap.offer(entry);
            } else {
                if(entry.getValue() > minHeap.peek().getValue()) {
                    minHeap.poll();
                    minHeap.offer(entry);
                }
            }
        }

        int[] res = new int[k];
        int i = 0;
        for(Map.Entry<Integer, Integer> entry : minHeap) {
            res[i++] = entry.getKey();
        }
        return res;
    }
}