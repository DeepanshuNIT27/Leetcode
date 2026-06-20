class Solution {
public:

string solve(int n ){

    if(n==1) return "1";

    string temp = solve(n-1);
    string ans = "";

    for(int i=0;i<temp.size();i++){
        int ch = temp[i];
        int j = i;
        while(j<temp.size() && temp[j] == ch){
             j++;
        }
        
       
        ans += to_string(j-i);
         ans += ch;
         i = j-1;
    }
    return ans;
}
    string countAndSay(int n) {
        
     return solve(n);

    }
};