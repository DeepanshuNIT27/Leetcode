class Solution {
public:

//EXPAND AROUND THE CENTER SOLUTION 
string  expand(int i , int j ,string s){
    int ans = 0;
    string p = "";
    while(i>=0 && j<s.size() && s[i]==s[j]){
       if(ans< j-i+1) p = s.substr(i,j-i+1);
       i--;
       j++;
    }
    return p;
}
    string longestPalindrome(string s) {
        string ans = "";

        for(int center=0;center<s.size();center++){
            //odd length
            int i = center;
            int j = center;

            auto ex1 = expand(i,j,s);

            // even length 
            i = center ;
            j = center + 1 ;

            auto ex2 = expand(i,j,s);

            if(ex2.size() > ans.size()) ans = ex2;
            if(ex1.size() > ans.size()) ans = ex1;
        }
        return ans;
    }
};