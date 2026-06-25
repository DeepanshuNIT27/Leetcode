class Solution {
public:
// COMPLEXITY O(4^N * N) BOTH TIME AND SPACE .

void solveRec(int i , string digits, string&temp,vector<string>&ans,unordered_map<char,string>&mp){

    if(i == digits.size()){
        ans.push_back(temp);
        return ;
    }

    for(auto&it : mp[digits[i]]){

        temp += it;
        solveRec(i+1,digits,temp,ans,mp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp = "";
        unordered_map<char,string>mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        solveRec(0,digits,temp,ans,mp);
        return ans;
    }
};