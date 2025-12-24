class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int count = 0;
        for(auto&it:capacity) {
            if(sum>0){
                sum -= it;
                count++;
            }
            else return count;
        }
        return count;
    }
};