class Solution {
public:

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
    long long sumSubarrayMins(vector<int>& arr) {
        auto next = nextsmallelement(arr);
        auto prev = prevsmallelement(arr);
        long long sum = 0;

        for(int i=0; i< arr.size() ;i++){
            long long nexti = next[i]==-1 ? next.size() : next[i] ;
            long long previ = prev[i];

            long  left = i - previ;
            long  right = nexti - i;
            sum = sum +(left*right)*arr[i];
        } 
        return sum ;
    }

    //MAXS SUMS
    vector<int>nextgreaterelement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i = v.size()-1; i>=0 ;i--){
        while(s.top()!= -1  && v[s.top()]< v[i]) s.pop();
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}
//prev small nikalo
vector<int>prevgreaterelement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i = 0; i<v.size() ;i++){
        while(s.top()!= -1 && v[s.top()]<=v[i]) s.pop();
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}
// koun element kitni bar aa rha check kr lo or usi number ko multiply kr ke add kr lo.
    long long sumSubarrayMaxs(vector<int>& arr) {
        auto next = nextgreaterelement(arr);
        auto prev = prevgreaterelement(arr);
        long long sum = 0;
       

        for(int i=0; i< arr.size() ;i++){
            long long nexti = next[i]==-1 ? next.size() : next[i] ;
            long long previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;
            sum = sum +(left*right)*arr[i];
        } 
        return sum ;
    }
    long long subArrayRanges(vector<int>& nums) {
        auto minsum = sumSubarrayMins(nums);
        auto maxsum =  sumSubarrayMaxs(nums);

        return maxsum - minsum ;
    }
};