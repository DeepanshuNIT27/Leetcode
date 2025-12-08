class Solution {
public:
   long long fun (long long  n){
    return  1LL*n*(n+1)/2;
   }
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long bound = fun(n);
        vector<int>ans;
        if(target<-bound || target>bound){
            return vector<int>();
        }
        //same parity hona chahiye
        if((bound - abs(target))%2!=0)  return vector<int>();

        long long currsum = 0LL;
        for(int i=n;i>=1;i--){
            long long temp = currsum - i;
            if(abs(target-temp)<= fun(i-1)){
                currsum -= i;
                ans.push_back(-i);
            }
            else{
                currsum += i;
                ans.push_back(i);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};