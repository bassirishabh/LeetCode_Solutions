class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals,(a,b) -> a[1]-b[1]);

        int k=Integer.MIN_VALUE;
        int count=0;

        for(int i=0;i<intervals.length;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(start>=k) k=end;
            else count++;
        }
        return count;
    }
}