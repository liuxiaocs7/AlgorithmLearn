/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    struct Node {
        bool is_word;
        Node* son[26];

        Node() {
            is_word = false;
            for(int i = 0; i < 26; i++) son[i] = NULL;
        }
    }*root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto p = root;
        for(auto &c : word) {
            int u = c - 'a';
            if(!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_word = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node *p, string &word, int i) {
        if(i == word.size()) return p->is_word;
        if(word[i] != '.') {
            int u = word[i] - 'a';
            if(!p->son[u]) return false;
            return dfs(p->son[u], word, i + 1);
        } else {
            for(int j = 0; j < 26; j++) {
                if(p->son[j] && dfs(p->son[j], word, i + 1)) return true; 
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// @lc code=end

