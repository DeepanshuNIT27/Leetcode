class Solution {
public:
    int countOdds(int low, int high) {
        int x = low%2==0 || low==high ? 0 : 1;
        int y = high%2==0 ? 0 : 1;
        int k = high - low ;
        if(low!=high) k--;
        if(k%2==0){
            cout<<x<<" "<<y<<" "<<k/2;
           return k/2 + x +y;
        }
        else {
            if(x) return k/2 + x + y;
            else return k/2 + 1 + x +y;
        }
        return 0;
    }
};