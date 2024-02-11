class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> umap=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            int diff=target-nums[i];
            if(umap.containsKey(diff)){
                return new int[]{umap.get(diff),i};
            }
            umap.put(nums[i],i);
        }
        return new int[]{};
    }
}