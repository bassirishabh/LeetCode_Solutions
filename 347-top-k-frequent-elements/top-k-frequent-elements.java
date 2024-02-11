class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> umap=new HashMap<>();

        for(int i:nums){
            umap.put(i,umap.getOrDefault(i,0)+1);
        }

        PriorityQueue<Map.Entry<Integer,Integer>> pq=new PriorityQueue<>((a,b) -> a.getValue() - b.getValue());

        for(Map.Entry<Integer,Integer> entry:umap.entrySet()){
            pq.offer(entry);
            if(pq.size()>k) pq.poll();
        }

        int result[]=new int[k];
        int index=0;
        while(!pq.isEmpty()){
            result[index++]=pq.poll().getKey();
        }
        return result;
    }
}