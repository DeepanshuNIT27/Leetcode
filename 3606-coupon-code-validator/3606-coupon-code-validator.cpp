class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>v;
        int n = code.size();
        for(int i=0;i<n;i++){
            bool flag = true;
            bool flag1 = true;
             string s = code[i];
             if(s.empty()) continue;
            for(int j=0;j<s.size();j++){
                if(!(s[j]>='a'&& s[j]<='z' || s[j]>='A' && s[j]<='Z' || s[j]>='0' && s[j]<='9' || s[j]=='_')){
                    flag = false;
                    break;
                }
            }
             string p = businessLine[i];
            if(!(p=="electronics" || p=="grocery" || p=="pharmacy" || p== "restaurant")){
                flag1 =false;
            }
            if(flag && flag1 && isActive[i]){
             v.push_back({businessLine[i],code[i]});
            }

        }
        vector<string>ans;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};