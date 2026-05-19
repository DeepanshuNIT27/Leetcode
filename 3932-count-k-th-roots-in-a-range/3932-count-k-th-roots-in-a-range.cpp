class Solution {
public:
bool possible(int mid , int n,  int k){

    if(pow(mid,k)<=n) return true;
    return false;
}

int binary(int n , int k){
     if(n < 0) return -1;
        int low = 0;
        int high = 1e9; 
        int ans = 0;
        while(low<=high){
         int mid = (low + high)/2;

            if(possible(mid,n,k)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
}
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r-l+1;

        int right = binary(r,k);
        int left = binary(l-1,k);

        return right-left;
       
    }
};