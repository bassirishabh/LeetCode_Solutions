class Solution {
    List<List<Integer>> result=new ArrayList<List<Integer>>();

    public void backtrack(int[] candidates, int target,int index,List<Integer> cur){
        if(target==0){
            result.add(new ArrayList(cur));
        }
        else if (target < 0 || index >= candidates.length) {
            return;
        } else {
            cur.add(candidates[index]);
            backtrack(candidates, target - candidates[index], index,cur);

            cur.remove(cur.get(cur.size() - 1));
            backtrack(candidates, target,index + 1,cur);
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> cur = new ArrayList();
        backtrack(candidates,target,0,cur);
        return result;
    }
}