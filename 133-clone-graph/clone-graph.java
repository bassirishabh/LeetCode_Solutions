/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Node,Node> umap=new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node==null) return node;
        if(umap.containsKey(node)) return umap.get(node);
        Node newnode=new Node(node.val);
        umap.put(node,newnode);
        for(Node nei:node.neighbors){
            newnode.neighbors.add(cloneGraph(nei));
        }
        
        return newnode;
    }
}