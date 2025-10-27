class Solution {
public:
bool solveRec(string &s , string &p , int i , int j){
    //BASE CASE
    if(i == s.size() && j == p.size()) {
         return true;
    }
    if(j>=p.size()){
        return false;
    }

    bool currmatch = ( i<s.size() && ((s[i]==p[j]) || (p[j]=='.')));
    if(j+1<p.size() && p[j+1]=='*'){
         bool EmptyWala = solveRec(s,p,i,j+2);
         bool PreElementWala = currmatch &&  solveRec(s,p,i+1,j);
         return  EmptyWala || PreElementWala;
    }
    else if(currmatch){
        return solveRec(s,p,i+1,j+1);
    }
    else {
        return false;
    }
   
}
    bool isMatch(string s, string p) {
        return solveRec(s,p,0,0);
    }
};