class Solution {
    public int maximalRectangle(String[] matrix) {
        if(matrix.length == 0 || matrix[0].length() == 0) return 0;
        int n = matrix.length;
        int m = matrix[0].length();

        int[][] h = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i].charAt(j) == '1') {
                    h[i][j] = i == 0 ? 1 : h[i - 1][j] + 1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = Math.max(res, largestRectangleArea(h[i]));
        }
        return res;
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] f = new int[n];
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