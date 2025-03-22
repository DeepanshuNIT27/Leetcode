class TrieNode{
 public:
 char data;
 unordered_map<char,TrieNode*>children;
 bool isTerminal;
 TrieNode(char value){
    data = value;
    isTerminal = false;
 }
};
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
   
void findlcp(TrieNode* root , string &ans){
    if(root->isTerminal == true){
        return ;
    }
    TrieNode* child;
    if(root->children.size() == 1){
        for(auto i: root->children){
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else{
        return ;
    }
    findlcp(child,ans);
}
class Solution {
public:
 TrieNode* root = new TrieNode('-');
    string longestCommonPrefix(vector<string>& strs) {
        for(auto i:strs){
            insertWord(root,i);
        }
        string ans ="";
       findlcp(root,ans);
        return ans;
    }
};