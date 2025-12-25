class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
     priority_queue<long long>pq;
     for(auto&it:happiness) pq.push(it);
     long long sum = 0LL;
     int count = 0;
     while(k){
        sum += pq.top() - count > 0 ?  pq.top()-count : 0;
        count++;
        pq.pop();
        k--;
     }
    return sum;
    }
};