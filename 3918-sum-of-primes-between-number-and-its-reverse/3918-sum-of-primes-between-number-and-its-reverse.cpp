class Solution {
public:
    int sumOfPrimesInRange(int n) {
        vector<int>primes;
        for(int i=2 ;i<1005;i++){

            bool flag = true;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flag = false;
                    break;
                }
            }
            if(flag) primes.push_back(i);
        }
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int num  = stoi(s);
        int left = min(n,num);
        int  right = max(n,num);

        auto first = lower_bound(primes.begin(),primes.end(),left)-primes.begin();
        auto second = upper_bound(primes.begin(),primes.end(),right)-primes.begin();
       return accumulate(primes.begin()+first , primes.begin()+second,0);

    }
};