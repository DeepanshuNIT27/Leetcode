class Solution {
public:

// Recursion 
vector<string>solveRec(string&s,  unordered_map<string,bool>&dict ,int i){
 if(i== s.size()) return {""};

    vector<string>ans;
    string word ;
    for(int j =i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;

        //found a valid word;
      auto right = solveRec(s,dict,j+1);
        for(auto eachRightPart : right){
            string endPart;
            if(eachRightPart.size()>0) endPart = " " + eachRightPart;
            ans.push_back(word + endPart);
        }
    }
    return ans;
}

// Memoization
    unordered_map<int,vector<string>>dp;
    vector<string>solveMemo(string&s,  unordered_map<string,bool>&dict ,int i){
    if(i== s.size()) return {""};
   if(dp.find(i)!=dp.end()) return dp[i];
    vector<string>ans;
    string word ;
    for(int j =i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;

        //found a valid word;
      auto right = solveRec(s,dict,j+1);
        for(auto eachRightPart : right){
            string endPart;
            if(eachRightPart.size()>0) endPart = " " + eachRightPart;
            ans.push_back(word + endPart);
        }
    }
    dp[i] = ans;
    return dp[i];
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word : wordDict) dict[word] = 1;
      //  return solveRec(s,dict,0);

      return solveMemo(s,dict,0);
    }
};