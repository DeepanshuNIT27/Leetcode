class Solution {
public:
 const int mod = 1e9+7;
void prevsmall(vector<int>& arr,stack<int>st,vector<int>&prev){

    int n = arr.size();

    for(int i=0;i<n;i++){

        while(!st.empty() && arr[st.top()]>arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            prev[i] = st.top();
        }
        else{
            prev[i] = -1;
        }
        st.push(i);
    }
}

void nextsmall(vector<int>& arr,stack<int>st,vector<int>&next){
    int n = arr.size();

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && arr[st.top()]>=arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            next[i] = st.top();
        }
        else{
            next[i] = n;
        }
        st.push(i);
    }
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>prev(n);
        prevsmall(arr,st,prev);

        vector<int>next(n);
        nextsmall(arr,st,next);

        long long  ans = 0LL;
        for(int i=0;i<n;i++){
            int left = i - prev[i];
            int right = next[i] - i;

            ans = (ans + (1LL* left*right*arr[i])%mod)%mod;
        }   
return (int)ans ;
    }
};