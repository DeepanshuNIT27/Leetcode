class TrieNode{
 public:
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    TrieNode(char value){
        data = value;
        isTerminal = false;
    }

    void insertWord(TrieNode* root , string word){
         if(word.length()==0){
            root->isTerminal = true;
            return ;
     }
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            child = new TrieNode(ch);
            root->children[ch] = child;
        }
        insertWord(child,word.substr(1));
    }

    bool searchWord(TrieNode* root ,string word){
        if(word.size()==0){
            return root->isTerminal;
        }
        char ch = word[0];
        TrieNode* child ;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recursionKaAns = searchWord(child,word.substr(1));
        return recursionKaAns;
    }
    bool searchPrefix(TrieNode* root ,string word){
        if(word.size()==0){
            return true;
        }
        char ch = word[0];
        TrieNode* child ;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recursionKaAns = searchPrefix(child,word.substr(1));
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
      root->insertWord(root,word);
    }
    
    bool search(string word) {
        bool ans = root->searchWord(root,word);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = root->searchPrefix(root,prefix);
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