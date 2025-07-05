class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int>v(26,-1);
        int count = 0;
        for(int i=0;i<n;i++){
            int index = word[i]-'a';
            if(v[index]!=-1 && ((i-v[index]+1)>=4)){
            count++;
            for(int j=0;j<26;j++){
                v[j] = -1;
            }
            }
            else{
              if(v[index]==-1)  v[index] = i;
            }
        }
     return count;   
    }
};