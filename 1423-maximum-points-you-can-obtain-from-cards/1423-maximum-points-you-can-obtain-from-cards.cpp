class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        
        int j = k-1;
        int i = n-1;
        int leftsum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int rightsum = 0;
        int ans = 0;
        ans = max(leftsum,ans);

        while(j>=0){
            
            leftsum -= cardPoints[j];
            rightsum += cardPoints[i];

            ans = max( ans , leftsum + rightsum);

            j--;
            i--;
        }
        return ans;
    }
};