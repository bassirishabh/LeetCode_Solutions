class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();

        HashMap<Character,Character> hashmap=new HashMap<>(3);
        hashmap.put(')','(');
        hashmap.put('}','{');
        hashmap.put(']','[');

        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(hashmap.containsKey(ch)){
                if(st.empty() || st.peek()!=hashmap.get(ch)) return false;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
}