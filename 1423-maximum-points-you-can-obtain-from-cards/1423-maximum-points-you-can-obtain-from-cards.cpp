class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int j = k-1;
        int n = cardPoints.size();

        int sum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int ans  = 0;
        ans = max(ans,sum);
        while(j>=0){
            sum -= cardPoints[j];
            j--;
            sum += cardPoints[n-(k-j-1)];

            ans = max(ans,sum);
           
        }
        return ans;
        
    }
};