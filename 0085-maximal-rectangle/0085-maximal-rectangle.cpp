class Solution {
public:
//NEXT SMALLER
void Nextsmaller(vector<int>&a , vector<int>&ans){
    int n = a.size();
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        int element = a[i];
      while(st.top()!= -1 &&  a[st.top()]>=element){
        st.pop();
      }
      ans.push_back(st.top());
      st.push(i);
    }
}
//PREV SMALLER
void Prevsmaller(vector<int>&a , vector<int>&ans){
    int n = a.size();
    stack<int>st;
    st.push(-1);
    for(int i=0;i<n;i++){
        int element = a[i];
        while(st.top()!=-1 && a[st.top()]>=element){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>prev(matrix[0].size(),0);
        int fin = 0;
        for(int i=0;i<matrix.size();i++){
            vector<int>a(matrix[0].size());
            for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j] == '1')
                       a[j] = prev[j] + 1;
                    else
                    a[j] = 0;
            }
            vector<int>ans1;
            vector<int>ans2;
            Nextsmaller(a,ans1);
            Prevsmaller(a,ans2);
            reverse(ans1.begin(),ans1.end());
            for(int k=0;k<ans1.size();k++) if(ans1[k]==-1) ans1[k] = ans1.size();
            for(int z=0;z<ans1.size();z++){
                int width = ans1[z] - ans2[z] - 1;
                int height = a[z];
             fin = max(fin , width*height);
            }
            prev = a;
        }
        
        return fin;
    }
};