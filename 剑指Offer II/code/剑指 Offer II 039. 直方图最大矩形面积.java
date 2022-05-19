class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        // 左边最近且比当前柱子矮的位置下标
        int[] f = new int[n];
        // 右边最近且比当前柱子矮的位置下标
        int[] g = new int[n];
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < n; i++) {
            while(!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            f[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        stack.clear();
        for(int i = n - 1; i >= 0; i--) {
            while(!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            g[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = Math.max(res, heights[i] * (g[i] - f[i] - 1));
        }
        return res;
    }
}