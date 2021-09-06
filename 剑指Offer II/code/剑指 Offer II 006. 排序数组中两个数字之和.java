class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for(int i = 0, j = numbers.length - 1; i < j; ) {
            int sum = numbers[i] + numbers[j];
            if(sum == target) {
                return new int[]{i, j};
            } else if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return new int[0];
    }
}