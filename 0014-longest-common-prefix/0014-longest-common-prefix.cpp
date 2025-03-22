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
    void search (TrieNode* root , string word, int &count){
        if(word.size()==0){
            return ;
        }
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
            count++;
        }
        else{
            return ;
        }
        search(child,word.substr(1),count);
    }
};
class Solution {
public:
 TrieNode* root = new TrieNode('-');
    string longestCommonPrefix(vector<string>& strs) {
        auto s = strs[0];
      root->insertWord(root,s);
       
        int ans = INT_MAX;
        for(int i=1;i<strs.size();i++){
            auto word = strs[i];
             int count = 0;
          root->search(root,word,count);
            ans = min(ans,count);
        }
        return strs[0].substr(0,ans);
        
    }
};