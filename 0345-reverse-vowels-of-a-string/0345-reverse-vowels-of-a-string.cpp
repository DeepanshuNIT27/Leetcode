class Solution {
public:
    string reverseVowels(string s) {
        int i =0;
        int j = s.size()-1;
        while(i<=j){
            int ch1 = s[i];
            int ch2 = s[j];
            if((!(ch1==97 || ch1==101 || ch1==105 || ch1==111 || ch1==117 || ch1==65 ||ch1==69 ||ch1==73 || ch1==79 || ch1==85))){
               i++;
            }
            else if((!(ch2==97 || ch2==101 || ch2==105 || ch2==111 || ch2==117 || ch2==65 ||ch2==69 ||ch2==73 || ch2==79 || ch2==85))){
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