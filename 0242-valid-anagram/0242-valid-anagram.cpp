class Solution {
public:
    bool isAnagram(string s, string t) {
        // SORTING METHOD 1
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        else{
            return false;
        }

        
        // unordered_map<char,int>freq1;
        // unordered_map<char,int>freq2;
        // for(int i=0 ;i< s.length(); i++){
        //     char ch = s[i];
        //     freq1[ch]++;
        // }
        // for(int j =0 ;j< t.length() ;j++){
        //     char ch = t[j];
        //     freq2[ch]++;
        // }
        //  for(int j =0 ;j< t.length() ;j++){
        //     char ch = t[j];
        // if(freq2[ch]>freq1[ch] || s.length()> t.length()){
        //    return false;
        // }
        // }
        
        // return true;
    }
};