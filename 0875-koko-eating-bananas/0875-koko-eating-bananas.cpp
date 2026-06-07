class Solution {
public:

bool possible(int k , vector<int>&piles, int h){
      int n = piles.size();
    for(int i=0;i<n;i++){
          
        int time = piles[i]/k ;
        time += piles[i]%k !=0 ? 1 : 0;
        h -= time;

        if(h<0) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        int e  = 1e9;
        int ans = 0;

        while(s<=e){
            int k = s + (e-s)/2;

            if(possible(k,piles,h)){
                ans  = k;
                e = k-1;
            }
            else {
                s = k+1;
            }
        }
        return ans ;
    }
};