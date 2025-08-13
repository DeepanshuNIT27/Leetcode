class Solution {
public:
void solve(string &a, string &b , int i , int j ,string &ans, int &carry){
    //base case
    if(i<0 &&j<0 && carry==0){
        return ;
    }
       int sum = carry;
       if(i>=0) sum+= a[i]-'0';
       if(j>=0) sum += b[j]-'0';
       carry = sum/10;
       ans.push_back((sum%10)+'0');
       solve(a,b,i-1,j-1,ans,carry);
}
    string addStrings(string num1, string num2) {
        int i=0;
        int j =0;
        int carray =0;
        string ans = "";
        solve(num1,num2,num1.size()-1, num2.size()-1,ans,carray);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};