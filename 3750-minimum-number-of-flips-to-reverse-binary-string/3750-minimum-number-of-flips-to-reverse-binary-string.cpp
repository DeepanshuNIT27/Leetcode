class Solution {
public:
    int minimumFlips(int n) {
        string ans = "";
        while(n){
            ans.push_back((n%2)+'0');
            n = n/2;
        }
        int i = 0;
        int j= ans.size()-1;
        int count = 0;
        while(i<=j){
            if(ans[i]!=ans[j]) count += 2;
            i++;
            j--;
        }
        return count;
    }
};