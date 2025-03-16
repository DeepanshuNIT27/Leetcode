class Solution {
public:
class Info{
public:
    int first ;
    int second;
    Info(int a, int b){
        first = a;
        second = b;
    }
};
class compare{
    public:
    bool operator()(Info*a ,Info*b){
      return   a->second >b->second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    priority_queue<Info* ,vector<Info*>,compare>pq;
    int count = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
        if(count<k){
        Info* temp = new Info(it->first,it->second);
        pq.push(temp);
        count++;
        }
        else{
             auto element = pq.top();
          int number = element->second;
          if(it->second >number ){
            pq.pop();
        Info* temp = new Info(it->first,it->second);
        pq.push(temp);

        }
        }
    }
   while(!pq.empty()){
    auto element = pq.top();
    int number = element->first;
    ans.push_back(number);
    pq.pop();
   }
    
   
    return ans;
    }
};