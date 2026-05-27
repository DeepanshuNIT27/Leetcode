class Solution {
public:
//SARE SUBARRAYS KA MIN NIKAL OR USKA SUM KRO
// SARE SUBARRAYS KA MAX NIKALO OR USKA SUM KRO
// AB MAXSUM - MINSUM KR DO VHI ANS HAI 
void prevsmaller(vector<int>& nums ,  stack<int>st , vector<int>&minprev ){
    int n = nums.size();

    for(int i=0;i<n;i++){

        while(!st.empty() && nums[st.top()]>= nums[i]){
            st.pop();
        }

        if(st.empty()) {
            minprev[i] = -1;
        }
        else{
            minprev[i] = st.top();
        }

        st.push(i);
    }
}
void nextsmaller(vector<int>& nums ,  stack<int>st , vector<int>&minnext ){
    int n = nums.size();

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && nums[st.top()]> nums[i]){
            st.pop();
        }

        if(st.empty()) {
           minnext[i] = n;
        }
        else{
           minnext[i] = st.top();
        }

        st.push(i);
    }
}

void prevgreater(vector<int>& nums , stack<int>st,  vector<int>&maxprev ){
      
      int n = nums.size();

      for(int i=0;i<n;i++){

        while(!st.empty() && nums[st.top()]<= nums[i]){
            st.pop();
        }
        if(!st.empty()) {
            maxprev[i] = st.top();
        }
        else{
            maxprev[i] = -1;
        }
        st.push(i);
      }
}

void nextgreater(vector<int>& nums , stack<int>st,  vector<int>&maxnext ){
      
      int n = nums.size();

      for(int i=n-1;i>=0;i--){

        while(!st.empty() && nums[st.top()]< nums[i]){
            st.pop();
        }
        if(!st.empty()) {
            maxnext[i] = st.top();
        }
        else{
            maxnext[i] = n;
        }
        st.push(i);
      }
}
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        stack<int>st;
        vector<int>minprev(n);
        vector<int>minnext(n);
        prevsmaller(nums,st,minprev);
        nextsmaller(nums,st,minnext);

        vector<int>maxprev(n);
        vector<int>maxnext(n);
        prevgreater(nums,st,maxprev);
        nextgreater(nums,st,maxnext);
        long long mini = 0LL;
        for(int i=0;i<n;i++){
          
          int left = i - minprev[i];
          int right = minnext[i] - i;

          mini += (1LL* left*right*nums[i]);
    }
         long long maxi = 0LL;
        for(int i=0;i<n;i++){

        int left = i - maxprev[i];
        int right = maxnext[i] - i;
        
        maxi += (1LL* left*right*nums[i]);
    }  
    return maxi - mini;
}
};