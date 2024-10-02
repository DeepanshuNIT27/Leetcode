class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int pickP=0;
        int travelP=0;
        int lasthouseP=0;

         int pickM=0;
        int travelM=0;
        int lasthouseM=0;

         int pickG=0;
        int travelG=0;
        int lasthouseG=0;

        for(int i =0 ; i< garbage.size();i++){
            string currenthouse= garbage[i];
            for(int j =0;j<currenthouse.length();j++){
                char garbagetype = currenthouse[j];
                if(garbagetype=='P'){
                    pickP++;
                    lasthouseP=i;
                }
                 if(garbagetype=='M'){
                    pickM++;
                    lasthouseM=i;
                }
                 if(garbagetype=='G'){
                    pickG++;
                    lasthouseG=i;
                }
            }
        }
        for(int i=0; i<lasthouseP;i++){
            travelP= travelP+travel[i];
        }
        for(int i=0; i<lasthouseM;i++){
            travelM= travelM+travel[i];
        }
        for(int i=0; i<lasthouseG;i++){
            travelG= travelG+travel[i];
        }
        int totalpickuptime= pickP+pickM+pickG;
        int totaltraveltime= travelP+travelM+travelG;
        int totaltime=totalpickuptime+totaltraveltime;
        return totaltime;

    }
};