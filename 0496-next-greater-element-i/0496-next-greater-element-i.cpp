class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>ans(nums1.size(),0);
        vector<int>temp(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()) {
                temp[i] = st.top();
            }
            else {
                temp[i] = -1;
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
            ans[i] = temp[mp[nums1[i]]];
        }
        
        return ans ;
    }
};