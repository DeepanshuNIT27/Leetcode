class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int>ans;
        vector<vector<int>>v;
        int i =0;
        int j =0;
        while(i<nums1.size() && j<nums2.size()){
            auto element = nums1[i];
            auto element1 = nums2[j];
            int a = element[0];
            int b = element1[0];
            if(a==b){
                ans.push_back(a);
                ans.push_back(element[1]+element1[1]);
                v.push_back(ans);
                ans.clear();
                i++;
                j++;
            }
            else if(a>b){
                ans.push_back(b);
                ans.push_back(element1[1]);
                v.push_back(ans);
                 ans.clear();
                j++;
            }
            else{
                ans.push_back(a);
                ans.push_back(element[1]);
                v.push_back(ans);
                 ans.clear();
                i++;
            }
                    }
            while(i<nums1.size()){
                auto element = nums1[i];
                ans.push_back(element[0]);
                ans.push_back(element[1]);
                v.push_back(ans);
                 ans.clear();
                i++;
            }
              while(j<nums2.size()){
                auto element = nums2[j];
                ans.push_back(element[0]);
                ans.push_back(element[1]);
                v.push_back(ans);
                 ans.clear();
                j++;
            }
            return v;

        
    }
};