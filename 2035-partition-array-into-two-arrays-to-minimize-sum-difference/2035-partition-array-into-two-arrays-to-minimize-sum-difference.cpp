class Solution {
public:
//MEET IN MIDDLE LAGEGA YHA 
// complexity (n*2^n) time and O(2^n) space.

void generate(vector<int>&nums, vector<vector<int>>&store){

    int m = nums.size();
    for(int mask=0;mask<(1<<m);mask++){

        int sum = 0;
        int count = 0;

        for(int i=0;i<m;i++){
            if(mask&(1<<i)){
                 sum += nums[i];
                 count++;
            }
        }
        store[count].push_back(sum);
    }
}
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;

        vector<int>left(nums.begin(),nums.begin()+n);
        vector<int>right(nums.begin()+n,nums.end());

        vector<vector<int>>L(n+1);
        vector<vector<int>>R(n+1);

        generate(left,L);
        generate(right,R);

        for(int i=0;i<=n;i++){
            sort(R[i].begin(),R[i].end());
        }
    int total = accumulate(nums.begin(),nums.end(),0);
    int ans = INT_MAX;
        for(int cntL=0;cntL<=n;cntL++){
            
            int cntR =  n - cntL;
           
           for(int leftSum : L[cntL]){
               int target = total/2 - leftSum;

               auto&vec = R[cntR];
               auto it = lower_bound(vec.begin(),vec.end(),target);

               if(it!=vec.end()){
                 
                 int sum = leftSum + *it;
                 ans = min(ans, abs(total-2*sum));
               }

               if(it!=vec.begin()){
                it--;
                 int sum = leftSum + *it;
                 ans = min(ans, abs(total-2*sum));
               }
           }
        }
        return ans;
    }
};