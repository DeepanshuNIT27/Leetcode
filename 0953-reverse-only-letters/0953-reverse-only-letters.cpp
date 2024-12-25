class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            int d = (int) s[i];
            int e = (int) s[j];
            if(!((d>=65 && d<=90)||(d>=97 && d<=122))){
                i++;
            }
            else if(!((e>=65 && e<=90)||(e>=97 && e<=122))){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
        
    }
};