class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        int i = 0;
        int n = asteroids.size();
        long long mass1 = mass;
        sort(asteroids.begin(),asteroids.end());
        while(i<n){

            if(mass1 >= asteroids[i]) mass1+= asteroids[i];

            else {
                break;
            }
            i++;
        }
        return (i == n) ;
    }
};