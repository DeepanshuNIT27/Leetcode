class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>mp;
        for(auto num:s){
            mp[num]++;
        }
        priority_queue<pair<int,char>>pq;
  for(auto it = mp.begin();it!=mp.end();it++){

    pq.push({it->second,it->first});
  }
  while(!pq.empty()){
   auto front = pq.top();
   int k = front.first;
   while(k){
   ans.push_back(front.second);
   k--;}
   
   pq.pop();
  }
     return ans;   
    }
};