class Solution {
public:
 bool solve(vector<int>& matchsticks,vector<long long>&sides,int i){
    //base case
    if(i==matchsticks.size()){
      return  sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0;
    }
    bool ans = false;
    for(int j=0;j<sides.size();j++){
        if(matchsticks[i]<=sides[j]){
            sides[j] -= matchsticks[i];
            ans = ans || solve(matchsticks,sides,i+1);
            if(ans) return true;
             sides[j] += matchsticks[i];
        }
    }
    return ans;
 }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        long long sum = accumulate(matchsticks.begin(),matchsticks.end(),0LL);
        if(sum%4!=0) return false;
        long long sidesum = sum/4;
        //4 side rhta hai agr sara zero hua mtlb bna skte hai squre.
        vector<long long>sides(4,sidesum);
        int i= 0;
        // sort krne se kam recursive calls bnengi yha bina dp ke chal jayga
        sort(matchsticks.rbegin(), matchsticks.rend());
       return  solve(matchsticks,sides,0);
        
    }
};