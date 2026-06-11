class Solution {
public:
//WE WILL USE BUCKET SORT FOR SORTING WILL GROUP THE CHAR HAVING THE 
//SAME FREQUENCIES.
    string frequencySort(string s) {

        int n = s.size();
        unordered_map<char,int>mp;
        for(auto&it:s) mp[it]++;

        vector<vector<char>>buc(n+1);

        for(auto&it:mp){
            buc[it.second].push_back(it.first);
        }
        string ans = "";
      for(int i=n;i>=0;i--){
          for(char ch : buc[i]){
            ans.append(i,ch);
          }
      }
      return ans;
    }
};