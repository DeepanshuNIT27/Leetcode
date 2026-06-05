class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

       int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int,int>mp;
        for(auto&it:hand) mp[it]++;

        while(!mp.empty()){
            auto it = *mp.begin();
            int mini = it.first;
            int fre = it.second;

            for(int i=0;i< groupSize;i++){
                if(mp.find(mini+i)!=mp.end() && mp[mini+i]>=fre){
                    mp[mini+i] -= fre;
                    if(mp[mini+i] == 0) mp.erase(mini+i);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};