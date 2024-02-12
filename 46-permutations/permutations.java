class Solution {
    List<List<Integer>> result=new ArrayList<>();

    public void backtrack(int[] nums,List<Integer> curr){
        if(curr.size()==nums.length){
            result.add(new ArrayList<>(curr));
            return;
        }
        for(int num:nums){
            if(!curr.contains(num)){
                curr.add(num);
                backtrack(nums,curr);
                curr.remove(curr.size()-1);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        backtrack(nums,new ArrayList<>());
        return result;
    }
}