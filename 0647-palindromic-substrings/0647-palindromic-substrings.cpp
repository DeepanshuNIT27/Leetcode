class Solution {
public:
 int expandsaroundcenter(string s,int i ,int j){
    int count =0;
    while(i>=0&& j<s.length()&&s[i]==s[j]){
       count++;
i--;
j++;
    }
    return count;
 }
    int countSubstrings(string s) {
        int totalcount =0;
        for(int center=0 ; center<s.length();center++){
            //covering odd substring
            int i = center;
            int j = center;
            int oddsubstringcount= expandsaroundcenter(s,i,j);
            //covering even substring;
           i  = center;
        j= center+1;
            int evenstringcount= expandsaroundcenter(s,i,j);
             totalcount= totalcount+oddsubstringcount+evenstringcount;
        }
        return totalcount;
    }
};