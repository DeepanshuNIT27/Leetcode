class Solution {
public:
//EXPAND AROUND THE CENTER KA DP SOLUTION COMPLEXITY HAI O(N^2).
//ALSO EXPAND AROUND CENTER KA COMPLEXITY BHI O(N^2) HAI.

void solve(string s , int i , int j , int &start , int &length){
    
    int n = s.size();
    while(i>=0 && j<n && s[i]==s[j]) {

        if(j-i+1 > length){
            start = i;
            length = j-i+1;
        }
        i--;
        j++;
    }
}
    string longestPalindrome(string s) {
        int n  = s.size();
        
        int start = 0;
        int length = 1;

        for(int i=0;i<n;i++){
             
           //  odd length pal
             solve(s,i,i,start,length);

           // even length pal 
            solve(s,i,i+1,start , length);
        }

        return s.substr(start,length);
    }
};