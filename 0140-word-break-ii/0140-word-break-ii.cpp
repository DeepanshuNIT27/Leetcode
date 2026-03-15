class Solution {
public:
 void solveRec(string&s, unordered_set<string>&dict,int start ,string temp ,vector<string>&ans ){

    //Base case
     
    if(start == s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return ;
    }

    string word = "";

    for(int i = start;i<s.size();i++){
        word += s[i];

        if(dict.find(word)!=dict.end()){
         
          solveRec(s,dict,i+1,temp+word+' ',ans);
        }
    }

 }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<string>ans;
        string temp = "";
        //Recursion
       solveRec(s,dict,0,temp,ans);
       return ans;
    }
};