class CQueue {
    Deque<Integer> stk1;
    Deque<Integer> stk2;
    
    public CQueue() {
        stk1 = new ArrayDeque<>();
        stk2 = new ArrayDeque<>();
    }
    
    public void appendTail(int value) {
        stk1.offerLast(value);
    }
    
    public int deleteHead() {
        if (!stk2.isEmpty()) {
            return stk2.pollLast();
        }
        while (!stk1.isEmpty()) {
            stk2.offerLast(stk1.pollLast());
        }
        return stk2.isEmpty() ? -1 : stk2.pollLast();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */