class Solution {
public:
void normalise( string &str){
    char start='a';
    unordered_map<char,char>mapping;
    for(int i=0;i<str.length();i++){
        char stringkacharacter= str[i];
        if(mapping.find(stringkacharacter)==mapping.end()){
            mapping[stringkacharacter]= start;
            start++;
        }
    }
    for(int i=0;i<str.length();i++){
        char mappedcharacter= mapping[str[i]];
        str[i]=mappedcharacter;
    }
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        normalise(pattern);
        for(int i=0 ;i<words.size();i++){
            string currwords=words[i];
            normalise(currwords);
            if(currwords.compare(pattern)==0){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};