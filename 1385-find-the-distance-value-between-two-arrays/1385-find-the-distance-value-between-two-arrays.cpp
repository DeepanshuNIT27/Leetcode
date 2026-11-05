class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        int n = arr1.size();

        for(int i=0;i<n;i++){
            int index = lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();

            if(index == 0 && abs(arr1[i]-arr2[index])>d) {
                    ans +=1;
            }
            else if(index == arr2.size()){
                if(abs(arr2[index-1] - arr1[i]) > d) ans += 1;
            }
            else if(index >0 && abs(arr1[i]-arr2[index])>d && abs(arr1[i] - arr2[index-1])>d) {
                ans +=1  ;
            }
        }
        return ans;
    }
};