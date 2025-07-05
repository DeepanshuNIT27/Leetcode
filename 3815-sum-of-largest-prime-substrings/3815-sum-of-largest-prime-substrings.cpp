class Solution {
public:
 bool isPrime(long long n){
    if(n<=1) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else{
        for(long long i=3;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
    }
    return true;
 }
    long long sumOfLargestPrimes(string s) {
    unordered_map<long long,bool>mp;
    vector<long long>v(3,0);
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            string st = s.substr(i,j-i+1);
            if(st.size()==0) continue;
            long long num = stoll(st);
          bool ans = isPrime(num);
          if(ans){
           long long mini = *min_element(v.begin(),v.end());
           sort(v.begin(),v.end());
           if(num>mini && mp[num]==false){
            v[0] = num;
            mp[num] = true;
           }
          }
        }
    }
    long long z = accumulate(v.begin(),v.end(),0LL);
    if(z==0) return 0;
     return z;
    }
};