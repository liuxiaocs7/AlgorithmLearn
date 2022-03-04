class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for(String str : strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String sortStr = String.valueOf(arr);
            List<String> list = map.getOrDefault(sortStr, new ArrayList<>());
            list.add(str);
            map.put(sortStr, list);
        }
        return new ArrayList(map.values());
    }
}