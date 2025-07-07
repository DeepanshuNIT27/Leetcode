class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>ans;
        vector<string>st = { "electronics", "grocery", "pharmacy", "restaurant"};
        set<string>s(st.begin(),st.end());
        for(int i=0;i<code.size();i++){
            auto temp = code[i];
            bool good =  true;
            if(temp.empty()) good = false;
            for(int j=0;j<temp.size();j++){
                char d =  toupper(temp[j]);
                if( (d>='A'&& d<='Z') || (d>='0' && d<='9')|| d=='_'){

                }
                else 
                {good = false;
                break;
                }
            }
            bool good2 = true;
            if(s.find(businessLine[i])==s.end()) good2= false;
            if(good && good2 && isActive[i] ) ans.push_back({businessLine[i],code[i]});
        }
        sort(ans.begin(),ans.end());
        vector<string>final;
        for(int i=0;i<ans.size();i++){
            final.push_back(ans[i].second);
        }
        return final;
    }
};