class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {     
        vector<char>v = {'A','C','G','T'};
        unordered_set<string>st(bank.begin(),bank.end());
         queue<pair<string,int>>q;
         q.push({startGene,0});
         while(!q.empty()){
         string word = q.front().first;
         int  step = q.front().second;
         q.pop();
         if(word==endGene) return step;

         for(int i=0;i<8;i++){
            char original = word[i];
            for(int j=0;j<4;j++){
                word[i] = v[j];
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i] = original;
         }
         }
         return -1;
    }
};