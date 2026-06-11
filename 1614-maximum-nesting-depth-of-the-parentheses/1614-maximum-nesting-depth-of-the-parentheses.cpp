class Solution {
public:
    int maxDepth(string s) {
        
        int n = s.size();
        int maxi = 0;
        int curr = 0;

        for(int i=0;i<n;i++){

            if(s[i] == '('){
                curr++;
            }
            else if(s[i] == ')') {
                curr--;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};