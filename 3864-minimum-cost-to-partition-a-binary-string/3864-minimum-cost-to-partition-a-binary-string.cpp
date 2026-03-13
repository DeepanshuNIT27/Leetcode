class Solution {
public:
// REcusrsive solution
    long long solveRec(string&s,int &encCost , int&flatCost, vector<int>&presen,int i , int j ){
        //Base case 
        long long ans = LLONG_MAX;
        if(j==i) {
          if(s[i]=='0') return flatCost;
          else return encCost;
        }
       
        //odd case
        if((j-i+1)&1){
          long long oddans = LLONG_MAX;

          long long x = presen[j] - (i==0 ? 0 : presen[i-1]);
          if(x==0) oddans = flatCost;
          else oddans = ((j-i+1)*x*encCost);

          ans = min(ans,oddans);
        } 
        //even case
        else{
          long long x = presen[j] - (i==0 ? 0 : presen[i-1]);
          long long ans1 = LLONG_MAX;
          if(x==0) ans1 = flatCost;
          else ans1 = ((j-i+1)*x*encCost);
        long long mid = (i+j)/2;
          long long leftans = solveRec(s,encCost,flatCost,presen,i,mid);
          long long rightans = solveRec(s,encCost,flatCost,presen,mid+1,j);

          ans = min(ans1 , leftans+ rightans);
        }
        return ans;
        
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int>presen(n,0);
        if(s[0]=='0') presen[0] = 0;
        else presen[0] = 1;

        for(int i=1;i<n;i++){
            presen[i] = presen[i-1] + (s[i]-'0');
        }
     return    solveRec(s,encCost,flatCost,presen,0,n-1);
    }
};