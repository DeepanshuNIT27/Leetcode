class Solution {
public:
//KMP LOGEST SUFFIX MATCHES WITH PREFIX .
vector<int>kmp(string s){

    vector<int>lps(s.size(),0);
    for(int i=1;i<lps.size();i++){
        int prev_index = lps[i-1];

        while(prev_index >0 && s[i]!=s[prev_index]){
            prev_index = lps[prev_index - 1];
        }
        lps[i] = prev_index  + (s[i] == s[prev_index] ? 1 : 0);
    }
    return lps ;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string sa =  a + "#" + s;
        string sb = b + "#" + s;

        vector<int>va , vb ;

        vector<int>v = kmp(sa);
        for(int i=a.size();i<v.size();i++){
            int el = v[i];

            if(el == a.size()){
                int idx = i - 2*a.size();
                if(idx>=0) va.push_back(idx);
            }
        }
        v = kmp(sb);
         for(int i=b.size();i<v.size();i++){
            int el = v[i];

            if(el == b.size()){
                int idx = i - 2*b.size();
                if(idx>=0) vb.push_back(idx);
            }
        }

        vector<int>ans;
        if(va.size() == 0 || vb.size() == 0) return ans;
       
        for(int i=0;i<va.size();i++){
            auto bi = lower_bound(vb.begin(),vb.end(),va[i]) - vb.begin();
            if(bi!= vb.size() && abs(va[i] - vb[bi]) <=k){
                ans.push_back(va[i]);
                continue;
            }
            if(bi>0  && abs(va[i]-vb[bi-1])<=k){
                ans.push_back(va[i]);
            }

        }
        return ans;

    }
};