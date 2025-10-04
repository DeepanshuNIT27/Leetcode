class Solution {
public:
void BeautifulArr(vector<int>&v , int &ans , int &n , int currNum){
    //BASE CASE
    if(currNum == n+1){
        ans++;
        return;
    }

    for(int i=1;i<=n;i++){
    if(v[i]==0 && (currNum%i==0 || i%currNum==0)){
        v[i] = currNum;
        BeautifulArr(v,ans,n,currNum+1);
        v[i] = 0;
    }
    }
}
    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans = 0;
        BeautifulArr(v,ans,n,1);
        return ans;
    }
};