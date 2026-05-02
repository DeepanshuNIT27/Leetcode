class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        set<int>s1 = {2,5,6,9};
        set<int>s2 = {3,4,7};

        for(int i=0;i<=n;i++){
          
           bool flag1 = false;
           bool flag2 = true;
           int k = i;
            while(k){
                int digit = k%10;

                if(s1.find(digit)!=s1.end()) flag1 = true;
                if(s2.find(digit)!=s2.end()) flag2 = false;

                k = k/10;

            }
            if(flag1 && flag2) count++;
        }
        return count ;
        
    }
};