class Solution {
public:

// prevsmallest nikalo nextsmallest nikalo eska diff width hoga 
//current height tera height hoga mul kro store max.
void prevsmaller(vector<int>& heights,stack<int>st, vector<int>&prev){
    int n = heights.size();

    for(int i=0;i<n;i++){

        while(!st.empty() && heights[st.top()]>= heights[i]){
            st.pop();
        }
        if(!st.empty()){
            prev[i] = st.top();
        }
        else {
            prev[i] = -1;
        }
        st.push(i);
    }
}

void nextsmaller(vector<int>& heights,stack<int>st, vector<int>&next){
    int n = heights.size();

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && heights[st.top()]>= heights[i]){
            st.pop();
        }
        if(!st.empty()){
            next[i] = st.top();
        }
        else {
            next[i] = n;
        }
        st.push(i);
    }
}

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int>st;
        vector<int>prev(n);
        vector<int>next(n);
        prevsmaller(heights,st,prev);
        nextsmaller(heights,st,next);
        
        int maxi = 0;
        for(int i=0;i<n;i++){
          
          int width = next[i] - prev[i] - 1;
          int height = heights[i];

          maxi = max( maxi , width*height);
        }
        return maxi;
    }
};