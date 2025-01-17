class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>v(derived.size());
        v[0] = derived[0] ^ derived[derived.size()-1];
        for(int i =0 ;i<derived.size()-1 ;i++){
            v[i+1]= v[i]^ derived[i];
        }
        for(int j=0 ;j< v.size()-1 ;j++){
            int e = v[j]^ v[j+1];
            if(e!=derived[j]){
                return false;
            }
        }
        int z = v[0]^v[v.size()-1];
        if(derived[derived.size()-1]!=z){
            return false;
        }
        return true;
    }
};