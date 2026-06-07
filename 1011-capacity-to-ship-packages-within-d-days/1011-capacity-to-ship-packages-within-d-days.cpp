class Solution {
public:

bool possible(int wt ,vector<int>& weights, int days ){

    int n  = weights.size();
    int count = 1;
    int sum = 0;
    for(int i=0;i<n;i++){
         
         if(sum + weights[i]> wt){
            count++;
            sum  = weights[i];
         }
         else{
            sum += weights[i];
         }

         if(count> days) return false;
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int s  = *max_element(weights.begin(),weights.end());
        int e =  accumulate(weights.begin(),weights.end(),0);
        int ans  = 0;

        while(s<=e){

            int wt  =  s + (e-s)/2;

            if(possible(wt,weights,days)){
                ans = wt;
                e = wt - 1;
            }
            else{
                s = wt + 1;
            }
        }
        return ans;
    }
};