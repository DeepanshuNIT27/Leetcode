class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int ans = 0;
        unordered_map<int,int>mp;

        int i = 0;
        int j = 0;

        while(j<n){
          
           mp[fruits[j]]++;

           while(i<j && mp.size()>2){

            if(mp[fruits[i]]==1) mp.erase(fruits[i]);
            else mp[fruits[i]]--;

            i++;
           }

           ans = max(ans,j-i+1);
           j++;
        }
     return ans;
    }
};