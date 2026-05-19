class Solution {
public:

    int psum[201][205][205];

    int getSum(int val ,int r1,int c1, int r2, int c2){

        if(r1 > r2 || c1 > c2) return 0;

        return psum[val][r2+1][c2+1] 
              -psum[val][r1][c2+1]
              -psum[val][r2+1][c1]
              +psum[val][r1][c1];
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        memset(psum,0,sizeof(psum));

        // Step-1 find prefixsum for count of values > matrix[i][j].
        // psum[val] = count of cell with val > val

        for(int val = 0; val <= 200; val++){

            for(int i = 1; i <= n; i++){

                for(int j = 1; j <= m; j++){

                    psum[val][i][j] =
                        psum[val][i-1][j]
                      + psum[val][i][j-1]
                      - psum[val][i-1][j-1];

                    if(matrix[i-1][j-1] > val)
                        psum[val][i][j]++;
                }
            }
        }

        //STEP-2 count all matrix[i][j] that follows the rules

        int count = 0;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                int val = matrix[i][j];

                if(val == 0) continue;

                int r1 = max(0,i-val);
                int r2 = min(n-1,i+val);

                int c1 = max(0,j-val);
                int c2 = min(m-1,j+val);

                int total = getSum(val,r1,c1,r2,c2);

                //corners are removed

                if(i-val>=0 && j-val>=0 &&
                   matrix[i-val][j-val] > val)
                    total--;

                if(i-val>=0 && j+val<m &&
                   matrix[i-val][j+val] > val)
                    total--;

                if(i+val<n && j-val>=0 &&
                   matrix[i+val][j-val] > val)
                    total--;

                if(i+val<n && j+val<m &&
                   matrix[i+val][j+val] > val)
                    total--;

                if(total == 0)
                    count++;
            }
        }

        return count;
    }
};