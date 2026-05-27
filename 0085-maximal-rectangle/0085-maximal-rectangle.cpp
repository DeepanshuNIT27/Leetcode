class Solution {
public:
// har row ka height banao with help of previous row 
// now har row ko histrogram ki tarah treat kro 
// store max ans got from all rows.
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>height(m,0);
         int maxi = 0;
        for(auto &it : matrix){

            for(int col=0;col<m ; col++){
                if(it[col]=='1') height[col] += 1;
                else height[col] = 0;
            }
            int sz = height.size();
              stack<int>st;
              vector<int>prev(sz);
              vector<int>next(sz);
               prevsmaller(height,st,prev);
              nextsmaller(height,st,next);

             for(int i=0;i<sz;i++){
          
            int width = next[i] - prev[i] - 1;
              int h = height[i];

          maxi = max( maxi , width*h);
        }

        }
        return maxi;
    }
};