class Solution {
public:

void Erathenes(int n ,vector<bool>&isPrime){
    isPrime[0] = isPrime[1]  = false ;

    for(int i=2;i*i<=n;i++){

        if(isPrime[i]){

            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
}
    int countPrimes(int n) {
        if(n == 0 || n==1 ) return 0;
        vector<bool>isPrime(n+1,true);
         Erathenes(n,isPrime);
        int count = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};