class TrieNode{
 public:
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    TrieNode(char value){
        data = value;
        isTerminal = false;
    }

    void insertWord(TrieNode* root , string &word , int i){
         if(i>= word.length()){
            root->isTerminal = true;
            return ;
     }
        char ch = word[i];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            child = new TrieNode(ch);
            root->children[ch] = child;
        }
        insertWord(child,word,i+1);
    }

    bool searchWord(TrieNode* root ,string &word , int i){
        if(i>= word.size()){
            return root->isTerminal;
        }
        char ch = word[i];
        TrieNode* child ;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recursionKaAns = searchWord(child,word,i+1);
        return recursionKaAns;
    }
    bool searchPrefix(TrieNode* root ,string &word,int i){
        if(i>= word.size()){
            return true;
        }
        char ch = word[i];
        TrieNode* child ;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recursionKaAns = searchPrefix(child,word,i+1);
        return recursionKaAns;
    }
};
class Trie {
public:
  TrieNode* root;
   
    Trie() {
      root = new TrieNode('-');
    }
   
    
    void insert(string word) {
      root->insertWord(root,word,0);
    }
    
    bool search(string word) {
        bool ans = root->searchWord(root,word,0);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = root->searchPrefix(root,prefix,0);
        return ans;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */