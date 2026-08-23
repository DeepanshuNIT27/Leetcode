class Solution {
public:
   vector<int>p;

   void spf(){
    int maxi = p.size()-1;
     
      for(int i=2 ; i*i<=maxi ;i++){
           
           if(p[i] == i){
              for(int j=i*i ; j<=maxi ; j+=i){
                 if(p[j] == j){
                    p[j] = i ;
                 }
              }
           }
      }
   }

   vector<int>sp(int num){
     
     vector<int>temp;

     while(num > 1){

        int d = p[num];
        temp.push_back(d);

        while(num%d == 0) {
            num /= d;
        }
     }
     return temp;
   }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        p.resize(maxi+1,0);
        for(int i=0;i<=maxi;i++){
            p[i] = i;
        }
        spf();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>cnt;

        int i = 0;
        int j = 0;
        int ans = 0;

        while(j<n){

            if(mp.find(nums[j])!=mp.end()){
                auto z = mp[nums[j]];
                for(auto&it:z) cnt[it]++;
            }
            else {
              auto temp =   sp(nums[j]) ;
              mp[nums[j]] = temp;
              for(auto&it:temp) cnt[it]++;
            }

            while(cnt.size() > k){
                auto z = mp[nums[i]];
                for(auto&it:z) {
                    cnt[it]--;
                     if(cnt[it] == 0)      
                        cnt.erase(it);
                }
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
            }

    return ans ;        

    }
};