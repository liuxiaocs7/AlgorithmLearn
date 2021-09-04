class Solution {
    public int divide(int dividend, int divisor) {
        // 特判 -2^{31} -1
        if(dividend == 0x80000000 && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // 将被除数和除数都变为负数
        // 负数的数量
        int negative = 2;
        if(dividend > 0) {
            negative--;
            dividend = -dividend;
        }
        if(divisor > 0) {
            negative--;
            divisor = -divisor;
        }
        int res = divideCore(dividend, divisor);
        return negative == 1 ? -res : res;
    }

    private int divideCore(int dividend, int divisor) {
        int result = 0;
        while(dividend <= divisor) {
            int value = divisor;
            int quotient = 1;
            while(value >= 0xc0000000 && dividend <= value + value) {
                value += value;
                quotient += quotient;
            }
            // 结果加上最大可以上的商
            result += quotient;
            // 被除数减去最大因子
            dividend -= value;
        }
        return result;
    }
}