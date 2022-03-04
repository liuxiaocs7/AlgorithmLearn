class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> list = new ArrayList<>();
        for(String timePoint : timePoints) {
            String[] t = timePoint.split(":");
            int time = Integer.parseInt(t[0]) * 60 + Integer.parseInt(t[1]);
            list.add(time);
        }
        Collections.sort(list);

        int res = Integer.MAX_VALUE;
        for(int i = 0; i < list.size() - 1; i++) {
            res = Math.min(res, list.get(i + 1) - list.get(i));
        }
        res = Math.min(res, list.get(0) + 24 * 60 - list.get(list.size() - 1));
        return res;
    }
}