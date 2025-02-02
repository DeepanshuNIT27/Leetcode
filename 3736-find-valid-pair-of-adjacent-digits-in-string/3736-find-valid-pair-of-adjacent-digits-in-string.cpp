

class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int>map;
        string p ="";
        for(int i=0 ;i<s.size();i++){
            map[s[i]]++;
        }
        int count = 0;
        char prev = '0';
        for(int i=0 ;i<s.size();i++){
            char ch = s[i];
            char element = map[ch] +'0';

            if(ch == element && ch!=prev ){
             p.push_back(ch);
             count ++;
             prev = ch;
             if(count==2){
                return p;
             }
            }
           
            else{
             if(count>0 && prev!=ch){
                count = 0;
                p.pop_back();
                prev = '0';
             }
            }
        }
        if(p.size()==1){
            p.pop_back();
        }
            return p;
        }
};

