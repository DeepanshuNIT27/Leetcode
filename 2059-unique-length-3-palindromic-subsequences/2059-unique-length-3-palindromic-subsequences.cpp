// class Solution {
// public:
//     void printsubsequence(string s ,int index  , string w,set<string>&st)
//     {
//         //BASE CASE
//             if(w.length()== 3 && (w[0]==w[2])){
//              st.insert(w);
//             return ;
//         }
//         if(index== s.length()){
//             return ;
//         }
//         char ch = s[index];
//         printsubsequence(s,index+1 , w+ch , st);
//         printsubsequence(s, index+1 , w ,st);
//     }
    
//     int countPalindromicSubsequence(string s) {
//         set<string>st;
//         string w ;
//         int count = 0;
//         printsubsequence(s,0,w,st);
    
//     return st.size();
//     }
// };
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int,int>> arr(26,{-1,-1});
        for(int i=0;i<n;i++){
            char ch=s[i];
            int index=ch-'a';
            if(arr[index].first==-1){
                arr[index].first=i;
            }
            else arr[index].second=i;
        }
        int ans=0;
        for (int i=0;i<26;i++) {
            int first_index=arr[i].first;
            int last_index=arr[i].second;
            if(first_index==-1) 
                continue;
            unordered_set<char> st;
            for (int i = first_index+1; i < last_index; i++) {
                st.insert(s[i]);
            }
            ans+=st.size();
        }
        return ans;
    }
};
