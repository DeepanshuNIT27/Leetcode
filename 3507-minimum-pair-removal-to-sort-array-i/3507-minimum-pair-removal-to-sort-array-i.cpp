class Solution {
public:
bool sorted(vector<int>&v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]<v[i]) return false;
    }
    return true;
}
int mini(vector<int>v , int &index ){
    int sum = INT_MAX;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]+v[i+1]<sum){
            sum = v[i]+v[i+1];
            index = i;
        }
    }
    return sum;
}
    int minimumPairRemoval(vector<int>& nums) {
        vector<int>v = nums;
        int count = 0;
       while(!sorted(v)){
        int index  = -1;
        int d = mini(v,index);
        v[index] = d;
        v.erase(v.begin()+index+1);
        count++;
       }
       return count;
    }
};