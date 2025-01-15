class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits=0;
        int x=0;
        while(num2){
            num2=num2&(num2-1);
            bits++;
        }
        for(int i=31;i>=0;i--){
            if(!bits) break;
            if(num1 & (1<<i)){
                x+=(1<<i);
                bits--;

            } 
        }
        for(int i=0;i<=31;i++){
            if(!bits) break;
            if((num1&(1<<i)) ==0){
                x+=(1<<i);
                bits--;
            }
        }
        return x;
    }
};