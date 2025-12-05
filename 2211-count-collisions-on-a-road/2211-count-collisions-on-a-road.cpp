class Solution {
public:
    int countCollisions(string directions) {
        int index = -1;
        int n = directions.size();
        for(int i=0;i<n-1;i++){
            if(directions[i]=='S' || (directions[i]=='R' && directions[i+1]=='L')) index = i;
        }
        if(directions[n-1]=='S') index = n-1;
        bool left = false;
        int count = 0;
        for(int i=0;i<n-1;i++){
            if(directions[i]=='R' && directions[i+1]=='L'){
                count += 2;
                left = true;
                i++;
            }
            else if(directions[i]=='R' && i<=index) count+=1;
            else if(directions[i]=='L' && left == true) count+= 1;
            else if(directions[i]=='S') left = true;
        }
        if(n-2>=0 && directions[n-1]=='L' && directions[n-2]!='R' && left==true) count += 1;
        return count;
    }
};