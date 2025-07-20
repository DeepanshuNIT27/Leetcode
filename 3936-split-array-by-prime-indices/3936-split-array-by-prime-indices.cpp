class Solution {
public:
bool isprime(int n){
    if (n<=0 || n==1) return false;
    if (n==2 )return true;
    if (n%2==0) return false;
    for(int i=3;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
return true;
}
    long long splitArray(vector<int>& nums) {
        vector<long long>a;
        vector<long long>b;
 for(int i=0;i<nums.size();i++){
    if(isprime(i)){
        a.push_back(nums[i]);
    }
    else b.push_back(nums[i]);
 }
   long long ans1 = accumulate(a.begin(),a.end(),0LL);
    long long ans2 = accumulate(b.begin(),b.end(),0LL);
return abs(ans1-ans2);
    }
};