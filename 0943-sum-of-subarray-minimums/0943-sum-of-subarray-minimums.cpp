class Solution {
public:
//next small nikalo
vector<int>nextsmallelement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i = v.size()-1; i>=0 ;i--){
        while(s.top()!= -1  && v[s.top()]> v[i]) s.pop();
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}
//prev small nikalo
vector<int>prevsmallelement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i = 0; i<v.size() ;i++){
        while(s.top()!= -1 && v[s.top()]>=v[i]) s.pop();
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}
// koun element kitni bar aa rha check kr lo or usi number ko multiply kr ke add kr lo.
    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextsmallelement(arr);
        auto prev = prevsmallelement(arr);
        int sum = 0;
        const  int mod = 1e9 + 7 ;

        for(int i=0; i< arr.size() ;i++){
            int nexti = next[i]==-1 ? next.size() : next[i] ;
            int previ = prev[i];

            int left = i - previ;
            int right = nexti - i;
// dono ko multiply kro
            long long number_of_times = (left % mod * right % mod) % mod ;
            long long total = (number_of_times * arr[i]) % mod ;
            sum = (sum + total) % mod ;
        }
        return sum ;
    }
};