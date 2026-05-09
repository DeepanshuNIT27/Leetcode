class Solution {
public:

int expand(int i , int j , string s){
    int count = 0;
    while(i>=0 && j<s.size() && s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count ;
}
    int countSubstrings(string s) {
        
        int total = 0;
        for(int center=0;center<s.size();center++){

            //odd length 
          int   i  = center;
           int  j = center ;

            int ex1 = expand(i,j,s);

            //even length 
            i = center ;
            j = center+1;

            int ex2 = expand(i,j,s);

            total += ex1 + ex2;
        }

return total;
    }
};