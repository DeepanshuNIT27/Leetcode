class Solution {
public:
    int smallestNumber(int n) {
        int index = 0;
        for(int i=0;i<32;i++){
            if((n>>i) &1) index = i+1;
        }
        int count = 0;
        int ans = 0;
        while(index){
            ans += pow(2,count);
            count++;
            index--;
        }
        return ans;
    }
};