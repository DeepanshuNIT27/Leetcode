class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // create queue
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        // set bnao
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            string frontstring = front.first;
            int frontDistance  = front.second;

            if(frontstring == endWord){
                return frontDistance;
            }
            else{
            for(int index=0; index<frontstring.size();index++){
             char originalchar = frontstring[index];
             for(char ch='a' ;ch<='z';ch++){
                frontstring[index] = ch;
                //checking newstring is in dixtionary or not
            if(st.find(frontstring)!=st.end()){
                q.push({frontstring,frontDistance+1});
                st.erase(frontstring);
            }
             }
             //backtracking
            frontstring[index] = originalchar;
             }
            }
        }
return 0;
        
    }
};