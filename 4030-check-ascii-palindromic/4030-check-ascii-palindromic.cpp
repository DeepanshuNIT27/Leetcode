class Solution {
public:

bool solve(string&s){

    int i = 0;
    int j = s.size()-1;


    while(i<=j){
        if(s[i] !=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    bool isPalindromic(string s) {
        int n = s.size();
        string ans = "";

        for(int i=0;i<n;i++){

            int x = (int)s[i];

            string temp = "";
            while(true){

                if(temp.size() == 8) break;
                if(x%2 == 0) temp.push_back('0');
                else temp.push_back('1');

                x =  x>>1;
            }
            reverse(temp.begin(),temp.end());
            ans += temp;
        }

        return solve(ans);
    }
};