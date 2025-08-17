class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = 2*k+1;
        //you can use ceil also
      //  int row = ceil((double)n/side);
        int row = (n+side-1)/side;
        int col = (m+side-1)/side;
        return row*col;
    }
};