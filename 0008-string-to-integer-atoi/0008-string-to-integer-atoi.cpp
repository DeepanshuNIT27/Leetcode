class Solution {
public:
   int solve(string &s , int index , int sign, long long &ans){
    if(index==s.size() || !(isdigit(s[index])) ){
        return sign*ans;
    }
    int d = s[index] -'0';
    ans = ans*10 + d;
    if(sign*ans>INT_MAX) return INT_MAX;
    if(sign*ans<INT_MIN) return INT_MIN;
    return solve(s,index+1,sign,ans);

   }
    int myAtoi(string s) {
        int i= 0;
        int n = s.size();
        while(i<n && s[i]==' ') i++;
        int sign = 1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-')sign = -1;
            i++;
        }
        long long ans = 0;
    return solve(s, i, sign, ans);
    }
};