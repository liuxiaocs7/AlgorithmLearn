class KthLargest {
    private PriorityQueue<Integer> minHeap;
    private int size;

    public KthLargest(int k, int[] nums) {
        size = k;
        minHeap = new PriorityQueue<>();
        for(int num : nums) {
            add(num);
        }
    }
    
    public int add(int val) {
        if(minHeap.size() < size) {
            minHeap.offer(val);
        } else if(minHeap.peek() < val) {
            minHeap.poll();
            minHeap.offer(val);
        }
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */