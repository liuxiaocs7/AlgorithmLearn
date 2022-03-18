class Solution {

    private List<List<Integer>> res;
    private List<Integer> path;
    boolean[] vis;

    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        path = new ArrayList<>();
        vis = new boolean[nums.length + 10];
        Arrays.sort(nums);
        dfs(nums);
        return res;
    }

    private void dfs(int[] nums) {

        if(path.size() == nums.length) {
            res.add(new ArrayList(path));
            return;
        }

        for(int i = 0; i < nums.length; i++) {
            if(!vis[i]) {
                if(i != 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
                path.add(nums[i]);
                vis[i] = true;
                dfs(nums);
                vis[i] = false;
                path.remove(path.size() - 1);
            }
        }
    }
}