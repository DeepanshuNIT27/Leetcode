class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s =0;
        int e = n-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if( mid-1>=0 && mid+1<=n && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(  mid-1 >=0 && arr[mid]<arr[mid-1]){
                e= mid-1;
            }
            if(mid+1<=n && arr[mid]<arr[mid+1]){
                s= mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
};