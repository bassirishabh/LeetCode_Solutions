class Solution {
    class TrieNode{
        Map<Character, TrieNode> map = new HashMap<>();
        boolean flag = false;
    }
    TrieNode trieRoot;
    char[][] board; int m, n;
    List<String> output;
    boolean[][] viz;
    public List<String> findWords(char[][] board, String[] words) {
        this.board = board;
        this.m = board.length; this.n = board[0].length;
        this.trieRoot = new TrieNode();
        this.output = new ArrayList<>();

        for (String w:words) insert(w);

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                viz = new boolean[m][n];
                dfs(i, j, new StringBuilder(), trieRoot);
            }
        }
        return output;
    }

    private void dfs(int i, int j, StringBuilder sb, TrieNode curr){
        if (i<0 || i>=m || j<0 || j>=n || viz[i][j]) return;
        char c = board[i][j];
        if (!curr.map.containsKey(c)) return;

        viz[i][j] = true;
        curr = curr.map.get(c);
        sb.append(c);

        if (curr.flag){
            output.add(sb.toString());
            curr.flag = false;
        }

        dfs(i+1, j, sb, curr);
        dfs(i-1, j, sb, curr);
        dfs(i, j+1, sb, curr);
        dfs(i, j-1, sb, curr);

        viz[i][j] = false;
        sb.setLength(sb.length()-1);
    }

    private void insert(String word){
        TrieNode curr = trieRoot;
        for (char c:word.toCharArray()){
            if (!curr.map.containsKey(c)) curr.map.put(c, new TrieNode());
            curr = curr.map.get(c);
        }
        curr.flag = true;
    }
}