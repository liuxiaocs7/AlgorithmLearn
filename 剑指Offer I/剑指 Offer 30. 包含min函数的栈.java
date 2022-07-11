class MinStack {
    Deque<Integer> stk1;
    Deque<Integer> stk2;

    /** initialize your data structure here. */
    public MinStack() {
        stk1 = new ArrayDeque<>();
        stk2 = new ArrayDeque<>();
    }
    
    public void push(int x) {
        stk1.offerLast(x);
        if (stk2.isEmpty() || x <= min()) {
            stk2.offerLast(x);
        }
    }
    
    public void pop() {
        if (stk1.pollLast() == min()) {
            stk2.pollLast();
        }
    }
    
    public int top() {
        return stk1.peekLast();
    }
    
    public int min() {
        return stk2.peekLast();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */