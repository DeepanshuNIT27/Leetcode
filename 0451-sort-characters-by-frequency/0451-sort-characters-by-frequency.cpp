class Solution {
public:
//USING HEAP WILL SORT COMPLEXITY O(N* LONG N) SPACE O(N)
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>mp;
        for(auto&it:s) mp[it]++;
        priority_queue<pair<int,char>>pq;

        for(auto&it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int k = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while(k>0){
               ans += ch;
               k--;
            }
        }
        return ans;
    }
};