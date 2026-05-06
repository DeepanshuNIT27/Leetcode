class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int index = -1;
        int count = 0;
        for(int i=0;i<g.size();i++){
            auto it = lower_bound(s.begin()+index+1 , s.end(),g[i]);
            if(it!=s.end()){
                count++;
                index = it - s.begin();
            }
        }

return count ;
        
    }
};