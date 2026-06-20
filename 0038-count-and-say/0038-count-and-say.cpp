//ITERATIVE SOLUTION COMPLEXITY WILL BE SAME AS RECURSIVE ONLY DIFF IS 
// RECURSIVE CALL STACK
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=2;i<=n;i++){
            string temp = ans;
            ans.clear();
            for(int j=0;j<temp.size();j++){

                char ch = temp[j];
                int k = j;
                while(k<temp.size() && temp[k] == ch){
                    k++;
                }
                ans += to_string(k-j);
                ans += ch;

                j =  k-1;
            
            }
        }
        return ans;
    }
};