class MovingAverage {

    private int size;
    private int sum;
    private Queue<Integer> queue;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        this.size = size;
        this.sum = 0;
        this.queue = new LinkedList<>();
    }
    
    public double next(int val) {
        if(this.queue.size() < this.size) {
            this.queue.offer(val);
            sum += val;
        } else {
            int t = this.queue.poll();
            sum -= t;
            this.queue.offer(val);
            sum += val;
        }
        return (double)this.sum / this.queue.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */