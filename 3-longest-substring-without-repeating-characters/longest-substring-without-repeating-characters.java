class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> umap=new HashMap<>();

        int left=0;
        int right=0;
        int maxlen=0;
        while(right<s.length()){
            char curentchar=s.charAt(right);
            umap.put(curentchar, umap.getOrDefault(curentchar, 0) + 1);
            while(umap.get(curentchar)>1){
                char ch=s.charAt(left);
                umap.put(ch,umap.get(ch)-1);
                left++;
            }
            maxlen=Math.max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
}