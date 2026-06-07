class Solution {
public:
bool possible(int days ,vector<int>& bloomDay, int m , int k ){
     int n = bloomDay.size();
     int count = 0;
    for(int i=0;i<n;i++){
         
         if(bloomDay[i]<=days){
            count++;
         }
         else{
            count = 0;
         }
         if(count == k){
            m--;
            count = 0;
         }
         if(m == 0) return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
     int n = bloomDay.size();

     if(1LL*m*k > n ) return -1;
        
        int s = *min_element(bloomDay.begin(),bloomDay.end());
        int e = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(s<=e){
        
         int days = s + (e-s)/2;

         if(possible(days,bloomDay,m,k)){
            ans = days;
            e = days - 1;
         }
         else{
            s = days + 1;
         }
        }
        return ans;
    }
};