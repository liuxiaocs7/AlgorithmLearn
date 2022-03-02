class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        Set<String> set = new HashSet<>();
        set.addAll(Arrays.asList("+", "-", "*", "/"));
        for(String token : tokens) {
            if(!set.contains(token)) {
                stack.push(Integer.parseInt(token));
            } else {
                int b = stack.pop();
                int a = stack.pop();
                int res = 0;
                if("+".equals(token)) res = a + b;
                else if("-".equals(token)) res = a - b;
                else if("*".equals(token)) res = a * b;
                else res = a / b;
                stack.push(res); 
            }
        }
        return stack.peek();
    }
}