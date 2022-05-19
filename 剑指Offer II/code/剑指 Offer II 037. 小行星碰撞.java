class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();
        for(int asteroid : asteroids) {
            // 向右飞行的直接入栈
            if(asteroid > 0) {
                stk.push(asteroid);
            } else {  // 向左飞行
                while(!stk.isEmpty() && stk.peek() > 0 && -asteroid > stk.peek()) {
                    stk.pop();
                }
                if(!stk.isEmpty() && -asteroid == stk.peek()) {
                    stk.pop();
                } else if(stk.isEmpty() || stk.peek() < 0) {
                    stk.push(asteroid);
                }
            }
        }
        return stk.stream().mapToInt(i->i).toArray();
    }
}