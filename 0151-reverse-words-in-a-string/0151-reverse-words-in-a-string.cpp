class Solution {
public:
//O(N) space soln 
    string reverseWords(string s) {
        
        string t ;
        int n = s.size();
        int i = 0;

        while(i<n){

            while(i<n && s[i] == ' ') i++;

            if(i>=n) break;

            if(!t.empty()) t.push_back(' ');

            while(i<n && s[i]!=' '){
                t.push_back(s[i]);
                i++;
            }
        }

        reverse(t.begin(),t.end());

        int start = 0;
        for(int i=0;i<=t.size();i++){

            if(i == t.size() || t[i]==' '){
                reverse(t.begin()+start , t.begin()+i);
                start = i+1;
            }
        }
        return t;
    }
};