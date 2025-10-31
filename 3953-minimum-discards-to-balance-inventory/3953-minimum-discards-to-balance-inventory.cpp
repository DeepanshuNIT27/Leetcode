class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>mp;
        int n = arrivals.size();
        int count = 0;
        vector<bool>v(n,false);
        for(int i=0;i<w;i++){
           if (mp.find(arrivals[i]) != mp.end()){
            if(mp[arrivals[i]]<m) mp[arrivals[i]]++;
            else {
                count++;
                v[i] = true;
            }
        }
        else   mp[arrivals[i]]++;
    }
  int j = 0;
    for(int i = w;i<n;i++){
     if(v[j]==false) mp[arrivals[j]]--;
     j++;
     if(mp[arrivals[i]]==m){
        count++;
        v[i] = true;
     } 
     if(mp[arrivals[i]]<m){
        mp[arrivals[i]]++;
     }
    }
    return count;
    }
};