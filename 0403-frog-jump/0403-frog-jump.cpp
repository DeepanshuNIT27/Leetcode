class Solution {
public:
//Recursion 
 bool solveRec(unordered_set<int>&st, int sum ,int jump ,  int target){
    if(sum == target ) return true;
    if(sum>target) return false;
    bool ans1 = false ; bool ans2 = false; bool ans3 = false;
    if( jump-1 >0 && st.find(sum+jump-1)!=st.end()){
      ans1 = ans1 || solveRec(st,sum+jump-1,jump-1,target);
    }
    if(st.find(sum+jump)!=st.end()){
      ans2 = ans2 ||  solveRec(st,sum+jump,jump,target);
    }
    if(st.find(sum+jump+1)!=st.end()){
      ans3 =  ans3 || solveRec(st,sum+jump+1,jump+1,target);
    }

    return (ans1 || (ans2 || ans3));
 }

 // Memoization 
   bool solveMemo( unordered_map<int,int>&mp, int sum ,int jump ,  int target, vector<vector<int>>&dp){
    if(sum == target ) return true;
    if(sum>target) return false;
     if(jump > dp.size()) return false;
     if(mp.find(sum) == mp.end()) return false;

    if(dp[mp[sum]][jump]!=-1) return dp[mp[sum]][jump];
    bool ans1 = false ; bool ans2 = false; bool ans3 = false;
    if( jump-1 >0 && mp.find(sum+jump-1)!=mp.end()){
      ans1 = ans1 || solveMemo(mp,sum+jump-1,jump-1,target,dp);
    }
    if(mp.find(sum+jump)!=mp.end()){
      ans2 = ans2 ||  solveMemo(mp,sum+jump,jump,target,dp);
    }
    if(mp.find(sum+jump+1)!=mp.end()){
      ans3 =  ans3 || solveMemo(mp,sum+jump+1,jump+1,target,dp);
    }

    dp[mp[sum]][jump] = (ans1 || (ans2 || ans3));
    return dp[mp[sum]][jump];
 }

 //Tabulation
 bool solveTab( unordered_map<int,int>&mp,vector<int>& stones){
     int n = stones.size();
      vector<vector<int>>dp(n+1 , vector<int>(n+1,0)) ;
      dp[0][0] = 1;
     
      for(int i=0;i<n;i++){
        for(int jump=0;jump<=n;jump++){
            if(dp[i][jump]==0) continue;

            //try jump -1 
            if(jump-1>0){
                int next = stones[i] + jump - 1;
                if(mp.find(next)!=mp.end()){
                    dp[mp[next]][jump-1] = 1;
                }
            }

            // try jump
            if(jump>0){
               int next = stones[i] + jump;
                if(mp.find(next)!=mp.end()){
                    dp[mp[next]][jump] = 1;
                }
            }
            if(jump+1<=n){
             int next = stones[i] + (jump+1);
                if(mp.find(next) != mp.end()){
                    dp[mp[next]][jump+1] = 1;
                }
            }
        }
      }

      for(int j = 0; j <= n; j++){
        if(dp[n-1][j]) return true;
    }
    return false;
 }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[0]+1 != stones[1]) return false;
      // unordered_set<int>st(stones.begin(),stones.end()); --Rec soln
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[stones[i]] = i;
        int target = stones[n-1];
      //Recursion 
     // return   solveRec(st,1,stones[1],target);

      // Memoization
    //   vector<vector<int>>dp(n+1 , vector<int>(n+1,-1)) ;
    //  return solveMemo(mp,stones[1],1,target,dp);

      // Tabulation 

return solveTab(mp,stones);
    }
};