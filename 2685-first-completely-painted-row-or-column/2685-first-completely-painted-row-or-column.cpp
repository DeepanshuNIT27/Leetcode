class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>row;
        unordered_map<int,int>column;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                row[mat[i][j]]=i;column[mat[i][j]]=j;
            }
        }
        
        unordered_map<int,int>row_cnt;
        unordered_map<int,int>col_cnt;
        for(int i=0;i<arr.size();i++){
            row_cnt[row[arr[i]]]++;
            if(row_cnt[row[arr[i]]]==mat[0].size()) return i;
            col_cnt[column[arr[i]]]++;
            if(col_cnt[column[arr[i]]]==mat.size()) return i;

            
        }
        return -1;


   
    }
};