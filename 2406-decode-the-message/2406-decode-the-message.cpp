class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mapping;
        char space =' ';
        mapping[space]=space;
        char start='a';
        int index=0;
        while(start<='z'&& index<key.length()){
            char currentcharacter = key[index];
            if(mapping.find(currentcharacter)!= mapping.end()){
                index++;
            }
            else{
                mapping[currentcharacter]= start;
                start++;
                index++;
            }
        }

        string ans;
        for(int i=0;i<message.length();i++){
            char messagecharacter=message[i];
            char mappedcharacter = mapping[messagecharacter];
            ans.push_back(mappedcharacter);
        }
        return ans;
        
    }
};