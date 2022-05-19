class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(arr[mid] > arr[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
}