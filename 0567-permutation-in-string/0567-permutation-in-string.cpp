class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1;
     
        for(auto&it:s1) mp1[it]++;

        unordered_map<char,int>mp2 = mp1;

         int j = 0;
        for(int i=0;i<s2.size();i++){
            
            if(mp1.find(s2[i]) == mp1.end()){

                j = i+1;
                mp2 = mp1;
                continue;

            }

            while(mp2.find(s2[i])== mp2.end()){
                mp2[s2[j]]++;
                j++;
            }

            if(mp2[s2[i]] == 1){
                mp2.erase(s2[i]);
            }
            else {
                mp2[s2[i]]--;
            }

            if(mp2.size() == 0) return true;


        }
        return false;
    }
};