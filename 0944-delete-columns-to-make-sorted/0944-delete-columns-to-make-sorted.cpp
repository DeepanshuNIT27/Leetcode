class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       set<int>st;
       for(int i=0;i<strs.size()-1;i++){
        string temp1 = strs[i];
        string temp2 = strs[i+1];
        for(int j=0;j<temp1.size();j++){
            if(temp1[j]>temp2[j]){
                st.insert(j);
            }
        }
       } 
       return st.size();
    }
};