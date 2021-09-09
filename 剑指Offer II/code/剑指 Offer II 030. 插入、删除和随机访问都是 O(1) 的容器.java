class RandomizedSet {
    private Map<Integer, Integer> numToLocation;
    private List<Integer> nums;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        numToLocation = new HashMap<>();
        nums = new ArrayList<>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(numToLocation.containsKey(val)) {
            return false;
        }
        numToLocation.put(val, nums.size());
        nums.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!numToLocation.containsKey(val)) {
            return false;
        }
        int location = numToLocation.get(val);
        numToLocation.put(nums.get(nums.size() - 1), location);
        numToLocation.remove(val);
        nums.set(location, nums.get(nums.size() - 1));
        nums.remove(nums.size() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random random = new Random();
        int r = random.nextInt(nums.size());
        return nums.get(r);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */