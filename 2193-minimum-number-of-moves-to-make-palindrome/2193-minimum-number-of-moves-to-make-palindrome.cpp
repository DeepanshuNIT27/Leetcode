class Solution {
public:
//GREEDY SOLN DP NAHI LAGEGA .
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        int ans = 0;

        while(i<j){

            if(s[i]==s[j]){
                i++;
                j--;
            }

            else {
                int k = j;

                while(k>i && s[i]!=s[k]){
                    k--;
                }

            //ODD FREQUENCY 
            if(i==k){
                swap(s[i],s[i+1]);
                ans++;
            }

            else{
                while(k<j){
                    swap(s[k],s[k+1]);
                    k++;
                    ans++;
                }
                i++;
                j--;
            }
            }
        }
        return ans;

    }
};