class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> umap=new HashMap<>();
        List<List<String>> result=new ArrayList<>();

        for(String s:strs){
            char ch[]=s.toCharArray();
            Arrays.sort(ch);
            String sortedarray=new String(ch);
            if(!umap.containsKey(sortedarray)){
                umap.put(sortedarray,new ArrayList<>());
            }
            umap.get(sortedarray).add(s);
        }

        for(List<String> value:umap.values()){
            result.add(value);
        }
        return result;
    }
}