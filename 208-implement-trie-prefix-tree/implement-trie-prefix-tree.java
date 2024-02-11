class Trie {

    class Node {
        Map<Character,Node> map;
        boolean endofflag;
        public Node(){
            map=new HashMap<>();
            endofflag=false;
        }
    }

    Node root;

    public Trie() {
        root=new Node();
    }
    
    public void insert(String word) {
        Node curr=root;
        for(int i=0;i<word.length();i++){
            char c=word.charAt(i);
            if(!curr.map.containsKey(c)){
                curr.map.put(c,new Node());
            }
            curr=curr.map.get(c);
        }
        curr.endofflag=true;
    }
    
    public boolean search(String word) {
        Node curr=root;
        for(int i=0;i<word.length();i++){
            char ch=word.charAt(i);
            if(!curr.map.containsKey(ch)){
                return false;
            }
            curr=curr.map.get(ch);
        }
        return curr.endofflag;
    }
    
    public boolean startsWith(String prefix) {
        Node curr=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix.charAt(i);
            if(!curr.map.containsKey(ch)){
                return false;
            }
            curr=curr.map.get(ch);
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */