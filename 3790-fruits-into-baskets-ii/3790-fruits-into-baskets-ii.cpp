class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n  = fruits.size();
        vector<bool>v(n,false);
        for(int i=0;i<n;i++){
         int d = fruits[i];
         for(int j=0;j<n;j++){
            if(v[j]==false && baskets[j]>=d){
                v[j] =  true;
                break;
            }
            
         }
        }
        for(auto ans:v){
            if(ans==false) count++;
        }
         return count;
    }
   
};