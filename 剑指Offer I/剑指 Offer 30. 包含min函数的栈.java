class MinStack {

    private Stack<Integer> stk;
    private Stack<Integer> minStk;

    /** initialize your data structure here. */
    public MinStack() {
        stk = new Stack<>();
        minStk = new Stack<>();
    }
    
    public void push(int x) {
        stk.push(x);
        if(minStk.isEmpty() || minStk.peek() >= x) {
            minStk.push(x);
        }
    }
    
    public void pop() {
        int t = stk.pop();
        if(t == minStk.peek()) {
            minStk.pop();
        }
    }
    
    public int top() {
        return stk.peek();
    }
    
    public int min() {
        return minStk.peek();
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