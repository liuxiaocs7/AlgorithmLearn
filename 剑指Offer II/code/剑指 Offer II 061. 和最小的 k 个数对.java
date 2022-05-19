class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        Queue<int[]> maxHeap = new PriorityQueue<>(
            (o1, o2) -> o2[0] + o2[1] - o1[0] - o1[1]
        );
        for(int i = 0; i < Math.min(nums1.length, k); i++) {
            for(int j = 0; j < Math.min(nums2.length, k); j++) {
                if(maxHeap.size() < k) {
                    maxHeap.offer(new int[]{nums1[i],nums2[j]});
                } else {
                    int[] top = maxHeap.peek();
                    if(top[0] + top[1] > nums1[i] + nums2[j]) {
                        maxHeap.poll();
                        maxHeap.offer(new int[]{nums1[i], nums2[j]});
                    }
                }
            }
        }

        List<List<Integer>> res = new ArrayList<>();
        while(!maxHeap.isEmpty()) {
            int[] top = maxHeap.poll();
            res.add(Arrays.asList(top[0], top[1]));
        }
        return res;
    }
}