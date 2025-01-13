class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char,int>m;
        for(int i=0 ;i< n ;i++){
            auto ch = s[i];
            m[ch]++;
        }
        int count = 0;
        for(auto it = m.begin() ;it!=m.end();it++){
             auto d = it->second ;
             if( d==1 || d==2){
                continue;
             }
              else if(d%2==0 ){
                count = count + (d/2) -1;
             }
             else{
                count = count + d/2 ;
             }
        }
        return n- 2*count ;
    }
};