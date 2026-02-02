class Solution {
public:
    int countMonobit(int n) {
        
        int count = 0;
        for(int j=n;j>=0;j--){
            int i = j;
            bool flag = true;
            int prev = -1;
            while(i>0){
                if(i%2 != prev && prev!=-1){
                    flag = false ;
                    break;
                }
                prev = i%2;
                i = i/2;
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};