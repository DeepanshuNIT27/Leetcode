class Solution {
public:
    int numRabbits(vector<int>& answers) {  
        unordered_map<int,int>map;
        int count = 0;
        for(int i=0 ;i<answers.size();i++){
            map[answers[i]]++;
        }
        for(auto it = map.begin();it!=map.end();it++){
            int d = it->second %(it->first+1);
            int e = it->second /(it->first+1);
            if(it->first==0){
                count += it->second;
            }
            else if(it->second <= it->first+1){
                count = count + it->first +1 ;
            }
            else if(d==0){
                count = count + e*(it->first + 1);
            }
            else{
                count = count + e*(it->first+1) + it->first+1;
            }
        }
        return count ;
    }
};