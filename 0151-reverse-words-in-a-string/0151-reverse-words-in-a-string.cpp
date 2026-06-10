class Solution {
public:
//INPLACE O(1) SOLUTION USING 2 POINTER WILL DO STRING COMPRESSION 
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        int j=0;

        while(j<n){

            while(j<n && s[j]==' ') j++;

            while(j<n && s[j]!=' ') {
                s[i++] = s[j++];
            }

            while(j<n && s[j]==' ') j++;

            if(j<n) s[i++] = ' ';
        }

        s.resize(i);
        reverse(s.begin(),s.end());
        int start = 0;
        for(int i=0;i<=s.size();i++){
          
          if(i==s.size() || s[i]==' '){
             reverse(s.begin()+start , s.begin()+i);
             start = i+1;
          }
        }
        return s;
    }
};