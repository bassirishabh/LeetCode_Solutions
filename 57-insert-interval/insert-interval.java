class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> result=new ArrayList<>();

        for(int i=0;i<intervals.length;i++){
            if(intervals[i][1]<newInterval[0]){
                result.add(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){
                result.add(newInterval);
                newInterval=intervals[i];
            }else{
                newInterval[0]=Math.min(intervals[i][0],newInterval[0]);
                newInterval[1]=Math.max(intervals[i][1],newInterval[1]);
            }
        }
        result.add(newInterval);
        return result.toArray(new int[result.size()][]);
    }

}