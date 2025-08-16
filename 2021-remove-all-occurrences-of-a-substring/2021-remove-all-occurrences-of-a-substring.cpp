class Solution {
public:
 void removeocc(string &s , string &part){
    if(s.size()==0 || s.find(part)==string::npos){
        return ;
    }
    //1 case hm smbhalenge
    auto index = s.find(part);
    if(index!=string::npos){
 s.erase(index,part.size());
    }
    removeocc(s,part);
     
 }
    string removeOccurrences(string s, string part) {
        removeocc(s,part);
return s;
    }
};