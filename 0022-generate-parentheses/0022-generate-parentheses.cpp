class Solution {
public:
/*“This is a Catalan-number backtracking problem, so complexity is O(Cn·n) time and O(Cn·n) space including output.”*/

//Due to heavy bound many branches prune so complexity not 2^2N . 
void solve(int n , int open , int close , string&curr ,vector<string>&ans ){

    if(curr.size() == 2*n) {

      ans.push_back(curr);
        return ;
    }

    //'(' try kr
    if(open<n){
    curr.push_back('(');
    solve(n,open+1,close,curr,ans);
    curr.pop_back();
    }

    // try ')' but restricted manner
    if(close<open){
        curr.push_back(')');
        solve(n,open , close+1,curr,ans);
        curr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr = "";
        solve(n,0,0,curr,ans);
        return ans;
    }
};