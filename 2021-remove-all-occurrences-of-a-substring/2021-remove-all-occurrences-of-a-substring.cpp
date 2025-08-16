class Solution {
public:
 void removeocc(string &s , string &part){
    if(s.size()==0 || s.find(part)==string::npos){
        return ;
    }
    //1 case hm smbhalenge
    int index = s.find(part);
    if(index!=string::npos){
        //string jodna better option rather than erase
        string right = s.substr(0,index);
        string left = s.substr(index+part.size(),s.size());
        s= right+left;
     
    }
    removeocc(s,part);
     
 }
    string removeOccurrences(string s, string part) {
        removeocc(s,part);
return s;
    }
};