class Solution {
public:

bool validindex(string s, int start ,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
        
    }
    return true;
}
    bool validPalindrome(string s) {
        int i =0;
        int j = s.length()-1;

        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool ans1 =validindex( s,i+1,j);
                bool ans2 =validindex( s,i,j-1);
                bool finalans = (ans1|| ans2);
                return finalans;
        
            }
        }
        return true;
    }
};