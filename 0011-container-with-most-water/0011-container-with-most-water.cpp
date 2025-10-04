class Solution {
public:
    int maxArea(vector<int>& height) {
        int  l = 0;
        int r  = height.size()-1;
        long long ans = INT_MIN;
        while(l<r){
            int d =  min(height[l],height[r]);
            int z = r-l;
            ans = max(ans,d*z*1LL);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return (int)ans;
    }
};