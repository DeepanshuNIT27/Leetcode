class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>v(105,0);
        for(auto & log:logs){
            int birth = log[0];
            int death = log[1];
            v[birth-1950] += 1;
            v[death-1950] -= 1;
        }
        vector<int>pre(105,0);
        pre[0] = v[0];
        for(int i=1;i<v.size();i++){
          pre[i] = v[i] + pre[i-1];
        }
        int maxi = INT_MIN;
        int index = 0;
        for(int i=0;i<pre.size();i++){
            if(pre[i]>maxi) 
            {maxi = pre[i];
            index = i;
            }
        }
        return index+1950;
    }
};