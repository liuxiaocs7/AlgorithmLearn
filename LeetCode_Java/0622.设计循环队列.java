/*
 * @lc app=leetcode.cn id=622 lang=java
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
    int he, ta, k;
    int[] nums;

    public MyCircularQueue(int k) {
        this.k = k;
        nums = new int[k];
    }
    
    public boolean enQueue(int value) {
        if (isFull()) return false;
        nums[ta % k] = value;
        return ++ta > 0;
    }
    
    public boolean deQueue() {
        if (isEmpty()) return false;
        return ++he > 0;
    }
    
    public int Front() {
        return isEmpty() ? -1 : nums[he % k];
    }
    
    public int Rear() {
        return isEmpty() ? -1 : nums[(ta - 1) % k];
    }
    
    public boolean isEmpty() {
        return he == ta;
    }
    
    public boolean isFull() {
        return ta - he == k;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
// @lc code=end

