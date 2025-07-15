class Solution {
public:
    bool isValid(string word) {
        int size =  word.size();
        bool ans1 = false;
        bool ans2 = false;
        bool ans3 = true;
        vector<char>v = {'a','e','i','o','u','A','E','I','O','U'};
        for(auto s:word){
            if(!((s>='a'&& s<='z')|| (s>='A'&& s<='Z')|| (s>='0' && s<='9'))){
              ans3 = false;
              break;
            }
            if(find(v.begin(),v.end(),s)!=v.end()){
                ans1= true;
            }
             if(find(v.begin(),v.end(),s)==v.end() && !((s>='0' && s<='9'))){
                ans2 = true;
             }

        }
        if(size>=3 && ans1 && ans2 && ans3){
            return true;
        }
        return false;
    }
};