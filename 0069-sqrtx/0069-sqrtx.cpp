class Solution {
public:
    int mySqrt(int x) {
        int  s =0;
int e = x;
int ans = -1;
long long int  mid = s+(e-s)/2;
while(s<=e){
    long long int square = (long long int)mid*mid;
    if( square ==x){
        return mid;
    }
    if(square>x){
        e = mid-1;
    }
    else{
        ans=mid;
        s= mid+1;
    }
    mid = s+(e-s)/2;
}
return ans;
        

    }
};