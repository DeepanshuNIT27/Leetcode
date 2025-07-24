class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        int num = image[sr][sc];
       queue<pair<int,int>>q;
        vector<int>dx = {0,-1,1,0};
      vector<int>dy = {1,0,0,-1};
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
           auto front = q.front();
           q.pop();
           
           int x = front.first;
           int y = front.second;
               for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y + dy[i];
                if(newx>=0 && newx<row  &&  newy>=0 && newy<col &&visited[newx][newy]==false && image[newx][newy]==num){
                    q.push({newx,newy});
                    image[newx][newy] = color;
                    visited[newx][newy]=true;

                }
               }
            }
            return image;
        }
        
    
};