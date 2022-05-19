class Trie {
    private static class TrieNode {
        TrieNode children[];
        boolean isWord;

        public TrieNode() {
            children = new TrieNode[26];
        }
    }

    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode node = root;
        for(char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if(node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode node = root;
        for(char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if(node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
        }
        return node.isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for(char ch : prefix.toCharArray()) {
            int idx = ch - 'a';
            if(node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
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